#include <libft.h>

#define Overlap(a0,a1,b0,b1) (MIN(a0,a1) <= MAX(b0,b1) && MIN(b0,b1) <= MAX(a0,a1))
// IntersectBox: Determine whether two 2D-boxes intersect.
#define IntersectBox(x0,y0, x1,y1, x2,y2, x3,y3) (Overlap(x0,x1,x2,x3) && Overlap(y0,y1,y2,y3))
// PointSide: Determine which side of a line the point is on. Return value: -1, 0 or 1.
#define PointSide(px,py, x0,y0, x1,y1) SIGN(VXS((x1)-(x0), (y1)-(y0), (px)-(x0), (py)-(y0)))
// Intersect: Calculate the point of intersection between two lines.
#define Intersect(x1,y1, x2,y2, x3,y3, x4,y4) ((t_xy) { \
		VXS(VXS(x1,y1, x2,y2), (x1)-(x2), VXS(x3,y3, x4,y4), (x3)-(x4)) / VXS((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)), \
		VXS(VXS(x1,y1, x2,y2), (y1)-(y2), VXS(x3,y3, x4,y4), (y3)-(y4)) / VXS((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)) })

// Some hard-coded limits.

static unsigned NumSectors = 0;

/* Player: location */
static struct player
{
	t_xyz			where;
	t_xyz			velocity;
	float			angle;
	float			anglesin;
	float			anglecos;
	float 			yaw;
	unsigned char 	sector;
}					player;

static SDL_Surface* surface = NULL;

static void LoadData(void)
{
	FILE	*fp;
	char	Buf[256];
	char	word[256];
	
	FILE* fp = fopen("map.txt", "rt");
	if(!fp) { perror("map.txt"); exit(1); }
	char Buf[256], word[256], *ptr;
	t_xy vertex[MAXVERTICES], *vertexptr = vertex;
	float x,y,angle,number, numbers[MAXEDGES];
	int n, m;
	while(fgets(Buf, sizeof Buf, fp))
		switch(sscanf(ptr = Buf, "%32s%n", word, &n) == 1 ? word[0] : '\0')
		{
			case 'v': // vertex
				for(sscanf(ptr += n, "%f%n", &y, &n); sscanf(ptr += n, "%f%n", &x, &n) == 1; )
				{
					if(vertexptr >= vertex+MAXVERTICES)
					{
						ft_printf("@RERROR@@: Too many vertices, limit is %u\n", MAXVERTICES);
						exit(2);
					}
					*vertexptr++ = (t_xy) { x, y };
				}
				break;
			case 's': // sector
				sectors = realloc(sectors, ++NumSectors * sizeof(*sectors));
				t_sector* sect = &sectors[NumSectors-1];
				sscanf(ptr += n, "%f%f%n", &sect->floor,&sect->ceil, &n);
				for(m=0; sscanf(ptr += n, "%32s%n", word, &n) == 1 && word[0] != '#'; )
				{
					if(m >= MAXEDGES)
					{ fprintf(stderr, "ERROR: Too many edges in sector %u. Limit is %u\n", NumSectors-1, MAXEDGES); exit(2); }
					numbers[m++] = word[0]=='x' ? -1 : strtof(word,0);
				}
				sect->npoints   = m /= 2;
				sect->neighbors = malloc( (m  ) * sizeof(*sect->neighbors) );
				sect->vertex    = malloc( (m+1) * sizeof(*sect->vertex)    );
				for(n=0; n<m; ++n) sect->neighbors[n] = numbers[m + n];
				for(n=0; n<m; ++n)
				{
					int v = numbers[n];
					if(v >= vertexptr-vertex)
					{ fprintf(stderr, "ERROR: Invalid vertex number %d in sector %u; only have %u\n",
							v, NumSectors-1, (int)(vertexptr-vertex)); exit(2); }
					sect->vertex[n+1]  = vertex[v]; // TODO: bounds checking
				}
				sect->vertex[0] = sect->vertex[m];
				break;
			case 'p': // player
				sscanf(ptr += n, "%f %f %f %f", &x,&y, &angle,&number);
				player = (struct player) { {x,y,0},{0,0,0}, angle,0,0,0, number };
				player.where.z = sectors[player.sector].floor + EYEHEIGHT;
				player.anglesin = sinf(player.angle);
				player.anglecos = cosf(player.angle);
		}
	fclose(fp);
}
static void UnloadData(void)
{
	for(unsigned a=0; a<NumSectors; ++a)
		free(sectors[a].vertex), free(sectors[a].neighbors);
	free(sectors);
	sectors    = NULL;
	NumSectors = 0;
}

static int IntersectLineSegments(float x0,float y0, float x1,float y1,
		float x2,float y2, float x3,float y3)
{
	return IntersectBox(x0,y0,x1,y1, x2,y2,x3,y3)
		&& ABS(PointSide(x2,y2, x0,y0,x1,y1) + PointSide(x3,y3, x0,y0,x1,y1)) != 2
		&& ABS(PointSide(x0,y0, x2,y2,x3,y3) + PointSide(x1,y1, x2,y2,x3,y3)) != 2;
}

struct Scaler { int result, bop, fd, ca, cache; };

#define Scaler_Init(a,b,c,d,f) \
{ d + (b-1 - a) * (f-d) / (c-a), ((f<d) ^ (c<a)) ? -1 : 1, \
	ABS(f-d), ABS(c-a), (int)((b-1-a) * ABS(f-d)) % ABS(c-a) }

// Scaler_Next: Return (b++ - a) * (f-d) / (c-a) + d using the initial values passed to Scaler_Init().
static int Scaler_Next(struct Scaler* i)
{
	for(i->cache += i->fd; i->cache >= i->ca; i->cache -= i->ca) i->result += i->bop;
	return i->result;
}

		// Helper function for the antialiased line algorithm.
#define fpart(x) ((x) < 0 ? 1 - ((x) - floorf(x)) : (x) - floorf(x))
#define rfpart(x) (1 - fpart(x))
		static void plot(int x,int y, float opacity, int color)
		{
			opacity = powf(opacity, 1/2.2f);
			int *pix = ((int*) surface->pixels) + y * W + x;
			int r0 = (*pix >> 16) & 0xFF, r1 = (color >> 16) & 0xFF;
			int g0 = (*pix >>  8) & 0xFF, g1 = (color >>  8) & 0xFF;
			int b0 = (*pix >>  0) & 0xFF, b1 = (color >>  0) & 0xFF;
			int r = MAX(r0, opacity*r1);
			int g = MAX(g0, opacity*g1);
			int b = MAX(b0, opacity*b1);
			*pix = (r << 16) | (g << 8) | b;
		}
		static void line(float x0,float y0, float x1,float y1, int color)
		{
			// Xiaolin Wu's antialiased line algorithm from Wikipedia.
			int steep = fabsf(y1-y0) > fabsf(x1-x0);
			if(steep)   { float tmp; tmp=x0; x0=y0; y0=tmp; tmp=x1; x1=y1; y1=tmp; }
			if(x0 > x1) { float tmp; tmp=x0; x0=x1; x1=tmp; tmp=y0; y0=y1; y1=tmp; }
			float dx = x1-x0, dy = y1-y0, gradient = dy/dx;
			// handle first endpoint
			int xend = (int)(x0 + 0.5f);
			int yend = y0 + gradient * (xend - x0);
			float xgap = rfpart(x0 + 0.5f);
			int xpxl1 = xend; // this will be used in the main loop
			int ypxl1 = (int)(yend);
			if(steep)
			{
				plot(ypxl1,   xpxl1, rfpart(yend) * xgap, color);
				plot(ypxl1+1, xpxl1,  fpart(yend) * xgap, color);
			}
			else
			{
				plot(xpxl1, ypxl1  , rfpart(yend) * xgap, color);
				plot(xpxl1, ypxl1+1,  fpart(yend) * xgap, color);
			}
			float intery = yend + gradient; // first y-intersection for the main loop
			// handle second endpoint
			xend = (int)(x1 + 0.5f);
			yend = y1 + gradient * (xend - x1);
			xgap = fpart(x1 + 0.5);
			int xpxl2 = xend; //this will be used in the main loop
			int ypxl2 = (int)(yend);
			if(steep)
			{
				plot(ypxl2  , xpxl2, rfpart(yend) * xgap, color);
				plot(ypxl2+1, xpxl2,  fpart(yend) * xgap, color);
			}
			else
			{
				plot(xpxl2, ypxl2,  rfpart(yend) * xgap, color);
				plot(xpxl2, ypxl2+1, fpart(yend) * xgap, color);
			}
			// main loop
			for(int x = xpxl1 + 1; x < xpxl2; ++x, intery += gradient)
				if(steep)
				{
					plot((int)(intery)  , x, rfpart(intery), color);
					plot((int)(intery)+1, x,  fpart(intery), color);
				}
				else
				{
					plot(x, (int)(intery),  rfpart(intery), color);
					plot(x, (int)(intery)+1, fpart(intery), color);
				}
		}

		// BloomPostprocess adds some bloom to the 2D map image. It is merely a cosmetic device.
		static void BloomPostprocess(void)
		{
			const int blur_width = W/120, blur_height = H/90;
			float blur_kernel[blur_height*2+1][blur_width*2+1];
			for(int y=-blur_height; y<=blur_height; ++y)
			{
				for(int x=-blur_width; x<=blur_width; ++x)
				{
					float value = expf(-(x*x+y*y) / (2.f*(0.5f*MAX(blur_width,blur_height))));
					blur_kernel[y+blur_height][x+blur_width] = value * 0.3f;
					//printf("%10.3f", value);
				}
				//printf("\n");
			}

			static int pixels_original[W*H];
			static struct pixel { float r,g,b,brightness; } img[W*H];
			memcpy(pixels_original, surface->pixels, sizeof(pixels_original));
			int *pix = ((int*) surface->pixels);

			for(unsigned y=0; y<H; ++y)
				for(unsigned x=0; x<W; ++x)
				{
					int original_pixel = pixels_original[y*W+x];
					float r = (original_pixel >> 16) & 0xFF;
					float g = (original_pixel >>  8) & 0xFF;
					float b = (original_pixel >>  0) & 0xFF;
					float wanted_br  = original_pixel == 0xFFFFFF ? 1
						: original_pixel == 0x55FF55 ? 0.6
						: original_pixel == 0xFFAA55 ? 1
						: 0.1;
					float brightness = powf((r*0.299f + g*0.587f + b*0.114f) / 255.f, 12.f / 2.2f);
					brightness = (brightness*0.2f + wanted_br * 0.3f + MAX(MAX(r,g),b)*0.5f/255.f);
					img[y*W+x] = (struct pixel) { r,g,b,brightness };
				}

#pragma omp parallel for schedule(static) collapse(2)
			for(unsigned y=0; y<H; ++y)
				for(unsigned x=0; x<W; ++x)
					{
						int ypmin = MAX(0, (int)y - blur_height), ypmax = MIN(H-1, (int)y + blur_height);
						int xpmin = MAX(0, (int)x - blur_width),  xpmax = MIN(W-1, (int)x + blur_width);
						float rsum = img[y*W+x].r;
						float gsum = img[y*W+x].g;
						float bsum = img[y*W+x].b;
						for(int yp = ypmin; yp <= ypmax; ++yp)
							for(int xp = xpmin; xp <= xpmax; ++xp)
							{
								float r = img[yp*W+xp].r;
								float g = img[yp*W+xp].g;
								float b = img[yp*W+xp].b;
								float brightness = img[yp*W+xp].brightness;
								float value = brightness * blur_kernel[yp+blur_height-(int)y][xp+blur_width-(int)x];
								rsum += r * value;
								gsum += g * value;
								bsum += b * value;
							}
						int color = (((int)CLAMP(rsum,0,255)) << 16)
							+ (((int)CLAMP(gsum,0,255)) <<  8)
							+ (((int)CLAMP(bsum,0,255)) <<  0);
						pix[y*W+x] = color;
					}
		}

		/* fillpolygon draws a filled polygon -- used only in the 2D map rendering. */
		static void fillpolygon(const t_sector* sect, int color)
		{

			float square = MIN(W/20.f/0.8, H/29.f), X = square*0.8, Y = square, X0 = (W-18*square*0.8)/2, Y0 = (H-28*square)/2;
			const t_xy* const vert = sect->vertex;
			// Find the minimum and maximum Y coordinates
			float miny = 9e9, maxy = -9e9;
			for(unsigned a = 0; a < sect->npoints; ++a)
			{
				miny = MIN(miny, 28-vert[a].x);
				maxy = MAX(maxy, 28-vert[a].x);
			}
			miny = Y0 + miny*Y; maxy = Y0 + maxy*Y;
			// Scan each line within this range
			for(int y = MAX(0, (int)(miny+0.5)); y <= MIN(H-1, (int)(maxy+0.5)); ++y)
			{
				// Find all intersection points on this scanline
				float intersections[W];
				unsigned num_intersections = 0;
				for(unsigned a = 0; a < sect->npoints && num_intersections < W; ++a)
				{
					float x0 = X0+vert[a].y*X, x1 = X0+vert[a+1].y*X;
					float y0 = Y0+(28-vert[a].x)*Y, y1 = Y0+(28-vert[a+1].x)*Y;
					if(IntersectBox(x0,y0,x1,y1, 0,y,W-1,y))
					{
						t_xy point = Intersect(x0,y0,x1,y1, 0,y,W-1,y);
						if(isnan(point.x) || isnan(point.y)) continue;
						// Insert it in intersections[] keeping it sorted.
						// Sorting complexity: n log n
						unsigned begin = 0, end = num_intersections, len = end-begin;
						while(len)
						{
							unsigned middle = begin + len/2;
							if(intersections[middle] < point.x)
							{ begin = middle++; len = len - len/2 - 1; }
							else
								len /= 2;
						}
						for(unsigned n = num_intersections++; n > begin; --n)
							intersections[n] = intersections[n-1];
						intersections[begin] = point.x;
					}
				}
				// Draw lines
				for(unsigned a = 0; a+1 < num_intersections; a += 2)
					line(CLAMP(intersections[a],  0,W-1), y,
							CLAMP(intersections[a+1],0,W-1), y, color);
				//printf("line(%f,%d, %f,%d)\n", minx,y, maxx,y);
			}
		}


		static void DrawMap(void)
		{
			static unsigned process = ~0u; ++process;

			// Render the 2D map on screen
			SDL_LockSurface(surface);
			for(unsigned y=0; y<H; ++y)
				memset( (char*)surface->pixels + (y*W)*4, 0, (W)*4);

			float square = MIN(W/20.f/0.8, H/29.f), X = square*0.8, Y = square, X0 = (W-18*square*0.8)/2, Y0 = (H-28*square)/2;
			for(float x=0; x<=18; ++x) line(X0+x*X, Y0+0*Y, X0+ x*X, Y0+28*Y, 0x002200);
			for(float y=0; y<=28; ++y) line(X0+0*X, Y0+y*Y, X0+18*X, Y0+ y*Y, 0x002200);
			fillpolygon(&sectors[player.sector], 0x440000);
			for(unsigned c=0; c<NumSectors; ++c)
			{
				unsigned a = c;
				if(a == player.sector && player.sector != (NumSectors-1))
					a = NumSectors-1;
				else if(a == NumSectors-1)
					a = player.sector;

				const t_sector* const sect = &sectors[a];
				const t_xy* const vert = sect->vertex;
				for(unsigned b = 0; b < sect->npoints; ++b)
				{
					float x0 = 28-vert[b].x, x1 = 28-vert[b+1].x;
					unsigned vertcolor = a==player.sector ? 0x55FF55
						: 0x00AA00;

					line( X0+vert[b].y*X, Y0+x0*Y,
							X0+vert[b+1].y*X, Y0+x1*Y,
							(a == player.sector)
							? (sect->neighbors[b] >= 0 ? 0xFF5533 : 0xFFFFFF)
							: (sect->neighbors[b] >= 0 ? 0x880000 : 0x6A6A6A)
						);

					line( X0+vert[b].y*X-2, Y0+x0*Y-2, X0+vert[b].y*X+2, Y0+x0*Y-2, vertcolor);
					line( X0+vert[b].y*X-2, Y0+x0*Y-2, X0+vert[b].y*X-2, Y0+x0*Y+2, vertcolor);
					line( X0+vert[b].y*X+2, Y0+x0*Y-2, X0+vert[b].y*X+2, Y0+x0*Y+2, vertcolor);
					line( X0+vert[b].y*X-2, Y0+x0*Y+2, X0+vert[b].y*X+2, Y0+x0*Y+2, vertcolor);
				}
			}

			float c = player.anglesin, s = -player.anglecos;
			float px = player.where.y,    tx = px+c*0.8f, qx0 = px+s*0.2f, qx1=px-s*0.2f;
			float py = 28-player.where.x, ty = py+s*0.8f, qy0 = py-c*0.2f, qy1=py+c*0.2f;
			px = CLAMP(px,-.4f,18.4f); tx = CLAMP(tx,-.4f,18.4f); qx0 = CLAMP(qx0,-.4f,18.4f); qx1 = CLAMP(qx1,-.4f,18.4f);
			py = CLAMP(py,-.4f,28.4f); ty = CLAMP(ty,-.4f,28.4f); qy0 = CLAMP(qy0,-.4f,28.4f); qy1 = CLAMP(qy1,-.4f,28.4f);

			line(X0 + px*X, Y0 + py*Y,  X0 + tx*X, Y0 + ty*Y, 0x5555FF);
			line(X0 +qx0*X, Y0 +qy0*Y,  X0 +qx1*X, Y0 +qy1*Y, 0x5555FF);

			BloomPostprocess();

			SDL_UnlockSurface(surface);

			//static unsigned skip=0;
			//if(++skip >= 1) { skip=0; SDL_Flip(surface); }
		}
		/*
		   static int vert_compare(const struct xy* a, const struct xy* b)
		   {
		   if(a->y != b->y) return (a->y - b->y) * 1e3;
		   return (a->x - b->x) * 1e3;
		   }
		 */
		// Verify map for consistencies
		static void VerifyMap(void)
		{
			//int phase=0;
Rescan:
			//DrawMap(); SDL_Delay(100);

			// Verify that the chain of vertexes forms a loop.
			for(unsigned a=0; a<NumSectors; ++a)
			{
				const t_sector* const sect = &sectors[a];
				const t_xy* const vert = sect->vertex;

				if(vert[0].x != vert[ sect->npoints ].x
						|| vert[0].y != vert[ sect->npoints ].y)
				{
					fprintf(stderr, "Internal error: Sector %u: Vertexes don't form a loop!\n", a);
				}
			}
			// Verify that for each edge that has a neighbor, the neighbor
			// has this same neighbor.
			for(unsigned a=0; a<NumSectors; ++a)
			{
				const t_sector* sect = &sectors[a];
				const t_xy* const vert = sect->vertex;
				for(unsigned b = 0; b < sect->npoints; ++b)
				{
					if(sect->neighbors[b] >= (int)NumSectors)
					{
						fprintf(stderr, "Sector %u: Contains neighbor %d (too large, number of sectors is %u)\n",
								a, sect->neighbors[b], NumSectors);
					}
					t_xy point1 = vert[b], point2 = vert[b+1];

					int found = 0;
					for(unsigned d = 0; d < NumSectors; ++d)
					{
						const t_sector* const neigh = &sectors[d];
						for(unsigned c = 0; c < neigh->npoints; ++c)
						{
							if(neigh->vertex[c+1].x == point1.x
									&& neigh->vertex[c+1].y == point1.y
									&& neigh->vertex[c+0].x == point2.x
									&& neigh->vertex[c+0].y == point2.y)
							{
								if(neigh->neighbors[c] != (int)a)
								{
									fprintf(stderr, "Sector %d: Neighbor behind line (%g,%g)-(%g,%g) should be %u, %d found instead. Fixing.\n",
											d, point2.x,point2.y, point1.x,point1.y, a, neigh->neighbors[c]);
									neigh->neighbors[c] = a;
									goto Rescan;
								}
								if(sect->neighbors[b] != (int)d)
								{
									fprintf(stderr, "Sector %u: Neighbor behind line (%g,%g)-(%g,%g) should be %u, %d found instead. Fixing.\n",
											a, point1.x,point1.y, point2.x,point2.y, d, sect->neighbors[b]);
									sect->neighbors[b] = d;
									goto Rescan;
								}
								else
									++found;
							}
						}
					}
					if(sect->neighbors[b] >= 0 && sect->neighbors[b] < (int)NumSectors && found != 1)
						fprintf(stderr, "Sectors %u and its neighbor %d don't share line (%g,%g)-(%g,%g)\n",
								a, sect->neighbors[b],
								point1.x,point1.y, point2.x,point2.y);
				}
			}
			// Verify that the vertexes form a convex hull.
			for(unsigned a=0; a<NumSectors; ++a)
			{
				t_sector* sect = &sectors[a];
				const t_xy* const vert = sect->vertex;
				for(unsigned b = 0; b < sect->npoints; ++b)
				{
					unsigned c = (b+1) % sect->npoints, d = (b+2) % sect->npoints;
					float x0 = vert[b].x, y0 = vert[b].y;
					float x1 = vert[c].x, y1 = vert[c].y;
					switch(PointSide(vert[d].x,vert[d].y, x0,y0, x1,y1))
					{
						case 0:
							continue;
						case -1:
							fprintf(stderr, "Sector %u: Edges %u-%u and %u-%u create a concave turn. This would be rendered wrong.\n",
									a,  b,c, c,d);
							break;
						default:
							continue;
					}
					fprintf(stderr, "- Splitting sector, using (%g,%g) as anchor", vert[c].x,vert[c].y);

					// Insert an edge between (c) and (e),
					// where e is the nearest point to (c), under the following rules:
					// e cannot be c, c-1 or c+1
					// line (c)-(e) cannot intersect with any edge in this sector
					float nearest_dist     = 1e29f;
					unsigned nearest_point = ~0u;
					for(unsigned n = (d+1) % sect->npoints; n != b; n = (n+1)% sect->npoints) // Don't go through b,c,d
					{
						float x2 = vert[n].x, y2 = vert[n].y;
						float distx = x2-x1, disty = y2-y1;
						float dist = distx*distx + disty*disty;
						if(dist >= nearest_dist) continue;

						if(PointSide(x2,y2, x0,y0, x1,y1) != 1) continue;

						int ok = 1;

						x1 += distx*1e-4f; x2 -= distx*1e-4f;
						y1 += disty*1e-4f; y2 -= disty*1e-4f;
						for(unsigned f = 0; f < sect->npoints; ++f)
							if(IntersectLineSegments(x1,y1, x2,y2,
										vert[f].x,vert[f].y, vert[f+1].x, vert[f+1].y))
							{ ok = 0; break; }
						if(!ok) continue;

						// Check whether this split would resolve the original problem
						if(PointSide(x2,y2, vert[d].x,vert[d].y, x1,y1) == 1) dist += 1e6f;
						if(dist >= nearest_dist) continue;

						nearest_dist   = dist;
						nearest_point = n;
					}
					if(nearest_point == ~0u)
					{
						fprintf(stderr, " - ERROR: Could not find a vertex to pair with!\n");
						SDL_Delay(200);
						continue;
					}
					unsigned e = nearest_point;
					fprintf(stderr, " and point %u - (%g,%g) as the far point.\n", e, vert[e].x,vert[e].y);
					// Now that we have a chain: a b c d e f g h
					// And we're supposed to split it at "c" and "e", the outcome should be two chains:
					// c d e         (c)
					// e f g h a b c (e)

					t_xy* vert1   = malloc(sect->npoints * sizeof(*vert1));
					t_xy* vert2   = malloc(sect->npoints * sizeof(*vert2));
					signed char* neigh1 = malloc(sect->npoints * sizeof(*neigh1));
					signed char* neigh2 = malloc(sect->npoints * sizeof(*neigh2));

					// Create chain 1: from c to e.
					unsigned chain1_length = 0;
					for(unsigned n = 0; n < sect->npoints; ++n)
					{
						unsigned m = (c + n) % sect->npoints;
						neigh1[chain1_length]  = sect->neighbors[m];
						vert1[chain1_length++] = sect->vertex[m];
						if(m == e) { vert1[chain1_length] = vert1[0]; break; }
					}
					neigh1[chain1_length-1] = NumSectors;
					// Create chain 2: from e to c.
					unsigned chain2_length = 0;
					for(unsigned n = 0; n < sect->npoints; ++n)
					{
						unsigned m = (e + n) % sect->npoints;
						neigh2[chain2_length]  = sect->neighbors[m];
						vert2[chain2_length++] = sect->vertex[m];
						if(m == c) { vert2[chain2_length] = vert2[0]; break; }
					}
					neigh2[chain2_length-1] = a;
					// Change sect into using chain1.
					free(sect->vertex);    sect->vertex    = vert1;
					free(sect->neighbors); sect->neighbors = neigh1;
					sect->npoints = chain1_length;
					// Create another sector that uses chain2.
					sectors = realloc(sectors, ++NumSectors * sizeof(*sectors));
					sect = &sectors[a];
					#ifdef VisibilityTracking
						sectors[NumSectors-1] = (t_sector) { sect->floor, sect->ceil, vert2, chain2_length, neigh2, 1};
					#else
						sectors[NumSectors-1] = (t_sector) { sect->floor, sect->ceil, vert2, chain2_length, neigh2 };
					#endif
					// The other sector may now have neighbors that think
					// their neighbor is still the old sector. Rescan to fix it.
					goto Rescan;
				}
			}

			//printf("PHASE 2\n"); SDL_Delay(500);
			//if(phase == 0) { phase = 1; goto Rescan; }
			printf("%d sectors.\n", NumSectors);

		}

static void vline(int x, int y1,int y2, int top,int middle,int bottom)
{
    int *pix = (int*) surface->pixels;
    y1 = CLAMP(y1, 0, H-1);
    y2 = CLAMP(y2, 0, H-1);
    if(y2 == y1)
        pix[y1*W+x] = middle;
    else if(y2 > y1)
    {
        pix[y1*W+x] = top;
        for(int y=y1+1; y<y2; ++y) pix[y*W+x] = middle;
        pix[y2*W+x] = bottom;
    }
}

		/* Moves the player by (dx,dy) in the map, and also updates
		 * their anglesin/anglecos/sector properties properly.
		 */
		static void MovePlayer(float dx, float dy)
		{
			float px = player.where.x,    py = player.where.y;
			/* Check if this movement crosses one of this sector's edges
			 * that have a neighboring sector on the other side.
			 * Because the edge vertices of each sector are defined in
			 * clockwise order, PointSide will always return -1 for a point
			 * that is outside the sector and 0 or 1 for a point that is inside.
			 */
			const t_sector* const sect = &sectors[player.sector];
			for(int s = 0; s < sect->npoints; ++s)
				if(sect->neighbors[s] >= 0
						&& IntersectBox(px,py, px+dx,py+dy,
							sect->vertex[s+0].x, sect->vertex[s+0].y,
							sect->vertex[s+1].x, sect->vertex[s+1].y)
						&& PointSide(px+dx, py+dy,
							sect->vertex[s+0].x, sect->vertex[s+0].y,
							sect->vertex[s+1].x, sect->vertex[s+1].y) < 0)
				{
					player.sector = sect->neighbors[s];
					printf("Player is now in sector %d\n", player.sector);
					break;
				}

			player.where.x += dx;
			player.where.y += dy;
			player.anglesin = sinf(player.angle);
			player.anglecos = cosf(player.angle);
		}

		static void DrawScreen(void)
		{
			struct item { short sectorno,sx1,sx2; } queue[MAXQUEUE], *head=queue, *tail=queue;
			short ytop[W]={0}, ybottom[W], renderedsectors[NumSectors];
			for(unsigned x=0; x<W; ++x) ybottom[x] = H-1;
			for(unsigned n=0; n<NumSectors; ++n) renderedsectors[n] = 0;
			/*Begin whole-screen rendering from where the player is. */
			*head = (struct item) { player.sector, 0, W-1 };
			if(++head == queue+MAXQUEUE) head = queue;

			SDL_LockSurface(surface);

			while(head != tail)
			{
				/* Pick a sector & slice from queue to draw */
				const struct item now = *tail;
				if(++tail == queue+MAXQUEUE) tail = queue;

				if(renderedsectors[now.sectorno] & 0x21) continue; // Odd = still rendering, 0x20 = give up
				++renderedsectors[now.sectorno];
				/* Render each wall of this sector that is facing towards player. */
				const t_sector* const sect = &sectors[now.sectorno];
				/* This loop can be used to illustrate currently rendering window. Should be disabled otherwise. */
				//for(unsigned x=now.sx1; x<=now.sx2; ++x)
				//    vline(x, ytop[x], ybottom[x], 0x003300, 0x00AA00, 0x003300);

				for(int s = 0; s < sect->npoints; ++s)
				{
					/* Acquire the x,y coordinates of the two vertexes forming the edge of the sector */
					/* Transform the vertices into the player's view */
					float vx1 = sect->vertex[s+0].x - player.where.x, vy1 = sect->vertex[s+0].y - player.where.y;
					float vx2 = sect->vertex[s+1].x - player.where.x, vy2 = sect->vertex[s+1].y - player.where.y;
					/* Rotate them around the player's view */
					float pcos = player.anglecos, psin = player.anglesin;
					float tx1 = vx1 * psin - vy1 * pcos,  tz1 = vx1 * pcos + vy1 * psin;
					float tx2 = vx2 * psin - vy2 * pcos,  tz2 = vx2 * pcos + vy2 * psin;
					/* Is the wall at least partially in front of the player? */
					if(tz1 <= 0 && tz2 <= 0) continue;
					/* If it's partially behind the player, clip it against player's view frustrum */
					if(tz1 <= 0 || tz2 <= 0)
					{
						float nearz = 1e-4f, farz = 5, nearside = 1e-5f, farside = 20.f;
						// Find an intersetion between the wall and the approximate edges of player's view
						t_xy i1 = Intersect(tx1,tz1,tx2,tz2, -nearside,nearz, -farside,farz);
						t_xy i2 = Intersect(tx1,tz1,tx2,tz2,  nearside,nearz,  farside,farz);

						if(tz1 < nearz) { if(i1.y > 0) { tx1 = i1.x; tz1 = i1.y; } else { tx1 = i2.x; tz1 = i2.y; } }
						if(tz2 < nearz) { if(i1.y > 0) { tx2 = i1.x; tz2 = i1.y; } else { tx2 = i2.x; tz2 = i2.y; } }
					}

					// if(tz1 <= 0.07f) { tx1 = (0.07f-tz1) * (tx2-tx1) / (tz2-tz1) + tx1; tz1 = 0.07f; }
					// if(tz2 <= 0.07f) { tx2 = (0.07f-tz2) * (tx1-tx2) / (tz1-tz2) + tx2; tz2 = 0.07f; }
					/* Do perspective transformation */
					float xscale1 = (W*HFOV) / (tz1), yscale1 = (H*VFOV) / (tz1); int x1 = W/2 + (int)(-tx1 * xscale1);
					float xscale2 = (W*HFOV) / (tz2), yscale2 = (H*VFOV) / (tz2); int x2 = W/2 + (int)(-tx2 * xscale2);
					if(x1 >= x2) continue;
					if(x2 < now.sx1 || x1 > now.sx2) continue;
					/* Acquire and transform the floor and ceiling heights */
					float yceil  = sect->ceil  - player.where.z;
					float yfloor = sect->floor - player.where.z;
#define Yaw(y,z) (y + z*player.yaw)
					int y1a = H/2 + (int)(-Yaw(yceil, tz1) * yscale1), y1b = H/2 + (int)(-Yaw(yfloor, tz1) * yscale1);
					int y2a = H/2 + (int)(-Yaw(yceil, tz2) * yscale2), y2b = H/2 + (int)(-Yaw(yfloor, tz2) * yscale2);
					/* Check the edge type. neighbor=-1 means wall, other=boundary between two sectors. */
					int neighbor = sect->neighbors[s];
					float nyceil=0, nyfloor=0;

					if(neighbor >= 0)
					{
						/* Something is showing through this wall (portal). */
						/* Perspective-transform the floor and ceiling coordinates of the neighboring sector. */
						nyceil  = sectors[neighbor].ceil  - player.where.z;
						nyfloor = sectors[neighbor].floor - player.where.z;
					}
					int ny1a = H/2 + (int)( -Yaw(nyceil, tz1) * yscale1), ny1b = H/2 + (int)( -Yaw(nyfloor, tz1) * yscale1);
					int ny2a = H/2 + (int)( -Yaw(nyceil, tz2) * yscale2), ny2b = H/2 + (int)( -Yaw(nyfloor, tz2) * yscale2);

					/* Render the wall. */
					int beginx = MAX(x1, now.sx1), endx = MIN(x2, now.sx2);

#if defined(DepthShading) && !defined(TextureMapping)
					struct Scaler z_int  = Scaler_Init(x1,beginx,x2, tz1*8,tz2*8);
#endif
					struct Scaler ya_int = Scaler_Init(x1,beginx,x2, y1a,y2a);
					struct Scaler yb_int = Scaler_Init(x1,beginx,x2, y1b,y2b);
					struct Scaler nya_int = Scaler_Init(x1,beginx,x2, ny1a,ny2a);
					struct Scaler nyb_int = Scaler_Init(x1,beginx,x2, ny1b,ny2b);

					for(int x = beginx; x <= endx; ++x)
					{
						// Affine calculation of txtx would be:
						//    alpha : (x-x1) / (x2-x1)
						//    u0    : 0;
						//    u1    : 1023;
						//    txtx  : u0 + u1 * alpha;
						// Perspective-corrected calculation of txtx (from Wikipedia):
						//    txtx  : ((1-alpha) * (u0 / z0) + alpha * (u1 / z1)) 
						//          / (((1-alpha) / z0) + alpha/z1);
						// Unrolled for only one division with Maxima:
						//    txtx  : u0*z1*(x2-x) + u1*z0*(x-x1)
						//          / ((x2-x)*z1 + (x-x1)*z0);

#if defined(DepthShading) && !defined(TextureMapping)
						/* Calculate the Z coordinate for this point. (Only used for lighting.) */
						int z = Scaler_Next(&z_int);
#endif
						/* Acquire the Y coordinates for our floor & ceiling for this X coordinate */
						int ya = Scaler_Next(&ya_int);
						int yb = Scaler_Next(&yb_int);
						/* Clamp the ya & yb */
						int cya = CLAMP(ya, ytop[x],ybottom[x]);
						int cyb = CLAMP(yb, ytop[x],ybottom[x]);

						// Our perspective calculation produces these two:
						//     screenX = W/2 + -mapX              * (W*HFOV) / mapZ
						//     screenY = H/2 + -(mapY + mapZ*yaw) * (H*VFOV) / mapZ
						// To translate these coordinates back into mapX, mapY and mapZ...
						//
						// Solving for Z, when we know Y (ceiling height):
						//     screenY - H/2  = -(mapY + mapZ*yaw) * (H*VFOV) / mapZ
						//     (screenY - H/2) / (H*VFOV) = -(mapY + mapZ*yaw) / mapZ
						//     (H/2 - screenY) / (H*VFOV) = (mapY + mapZ*yaw) / mapZ
						//     mapZ = mapY / ((H/2 - screenY) / (H*VFOV) - yaw)
						//     mapZ = mapY*H*VFOV / (H/2 - screenY - yaw*H*VFOV)
						// Solving for X, when we know Z
						//     mapX = mapZ*(W/2 - screenX) / (W*HFOV)
						//
						// This calculation is used for visibility tracking
						//   (the visibility cones in the map)
						// and for floor & ceiling texture mapping.
						//
#define CeilingFloorScreenCoordinatesToMapCoordinates(mapY, screenX,screenY, X,Z) \
						do { Z = (mapY)*H*VFOV / ((H/2 - (screenY)) - player.yaw*H*VFOV); \
							X = (Z) * (W/2 - (screenX)) / (W*HFOV); \
							RelativeMapCoordinatesToAbsoluteOnes(X,Z); } while(0)
						//
#define RelativeMapCoordinatesToAbsoluteOnes(X,Z) \
						do { float rtx = (Z) * pcos + (X) * psin; \
							float rtz = (Z) * psin - (X) * pcos; \
							X = rtx + player.where.x; Z = rtz + player.where.y; \
						} while(0)

						/* Render ceiling: everything above this sector's ceiling height. */
						vline(x, ytop[x], cya-1, 0x111111 ,0x222222,0x111111);
						/* Render floor: everything below this sector's floor height. */
						vline(x, cyb+1, ybottom[x], 0x0000FF,0x0000AA,0x0000FF);

						/* Is there another sector behind this edge? */
						if(neighbor >= 0)
						{
							/* Same for _their_ floor and ceiling */
							int nya = Scaler_Next(&nya_int);
							int nyb = Scaler_Next(&nyb_int);
							/* Clamp ya2 & yb2 */
							int cnya = CLAMP(nya, ytop[x],ybottom[x]);
							int cnyb = CLAMP(nyb, ytop[x],ybottom[x]);
							/* If our ceiling is higher than their ceiling, render upper wall */

#ifdef DepthShading
							unsigned r1 = 0x010101 * (255-z), r2 = 0x040007 * (31-z/8);
#else
							unsigned r1 = 0xAAAAAA, r2 = 0x7C00D9;
#endif
							vline(x, cya, cnya-1, 0, x==x1||x==x2 ? 0 : r1, 0);
							ytop[x] = CLAMP(MAX(cya, cnya), ytop[x], H-1);

							// If our floor is lower than their floor, render bottom wall
							vline(x, cnyb+1, cyb, 0, x==x1||x==x2 ? 0 : r2, 0);
							ybottom[x] = CLAMP(MIN(cyb, cnyb), 0, ybottom[x]);

							/* These vlines can be used to illustrate the frame being rendered. */
							/* They should be disabled otherwise. */
							//vline(x, ytop[x],ybottom[x], 0x330000,0xAA0000,0x330000);
							//vline(x, cya,cyb, 0x330000,0xAA0000,0x330000);
						}
						else
						{
							/* There's no neighbor. Render wall. */
#ifdef DepthShading
							unsigned r = 0x010101 * (255-z);
#else
							unsigned r = 0xAAAAAA;
#endif
							vline(x, cya, cyb, 0, x==x1||x==x2 ? 0 : r, 0);
						}

						/* // uncomment this to see the process of a frame being rendered in real time.
						   SDL_UnlockSurface(surface);
						   SaveFrame2(surface); SDL_Flip(surface);
						   SDL_LockSurface(surface);*/

					}
					/* Schedule the other sector for rendering within the window formed by this wall. */
					if(neighbor >= 0 && endx >= beginx && (head+MAXQUEUE+1-tail)%MAXQUEUE)
					{
						*head = (struct item) { neighbor, beginx, endx };
						if(++head == queue+MAXQUEUE) head = queue;
						//if(tail-- == queue) tail = queue+MAXQUEUE-1;
						//*tail = (struct item) { neighbor, beginx, endx };
					}
				}
				++renderedsectors[now.sectorno];
			}

			SDL_UnlockSurface(surface);
			//static unsigned skip=0;
			//if(/*++skip >= 10 && */!map) { skip=0; SDL_Flip(surface); }
		}

		int				kappa(int argc, char** argv)
		{
			LoadData();
			VerifyMap();
			surface = SDL_SetVideoMode(W, H, 32, 0);

			SDL_EnableKeyRepeat(150, 30);
			SDL_ShowCursor(SDL_DISABLE);

			signal(SIGINT, SIG_DFL);

			//FILE* fp = fopen("actions.log", "rb");

			int wsad[4]={0,0,0,0}, ground=0, falling=1, moving=0, ducking=0, map=0;
			SDL_Event ev;
			float yaw = 0;
			for(;;)
			{

				DrawScreen();
				if(map)
					DrawMap();
				static unsigned skip=0;
				if(++skip >= 1) { skip=0; SDL_Flip(surface); }

				/* Vertical collision detection */
				float eyeheight = ducking ? DUCKHEIGHT : EYEHEIGHT;
				ground = !falling;
				if(falling)
				{
					player.velocity.z -= 0.05f; /* Add gravity */
					float nextz = player.where.z + player.velocity.z;
					if(player.velocity.z < 0 && nextz  < sectors[player.sector].floor + eyeheight)
					{
						/* Fix to ground */
						player.where.z    = sectors[player.sector].floor + eyeheight;
						player.velocity.z = 0;
						falling = 0;
						ground  = 1;
					}
					else if(player.velocity.z > 0 && nextz > sectors[player.sector].ceil)
					{
						/* Prevent jumping above ceiling */
						player.velocity.z = 0;
						falling = 1;
					}
					if(falling)
					{
						player.where.z += player.velocity.z;
						moving = 1;
					}
				}
				/* Horizontal collision detection */
				if(moving)
				{
					float px = player.where.x,    py = player.where.y;
					float dx = player.velocity.x, dy = player.velocity.y;

					const t_sector* const sect = &sectors[player.sector];
					/* Check if the player is about to cross one of the sector's edges */
					for(int s = 0; s < sect->npoints; ++s)
						if(IntersectBox(px,py, px+dx,py+dy,
									sect->vertex[s+0].x, sect->vertex[s+0].y,
									sect->vertex[s+1].x, sect->vertex[s+1].y)
								&& PointSide(px+dx, py+dy,
									sect->vertex[s+0].x, sect->vertex[s+0].y,
									sect->vertex[s+1].x, sect->vertex[s+1].y) < 0)
						{
							float hole_low = 9e9, hole_high = -9e9;
							if(sect->neighbors[s] >= 0)
							{
								/* Check where the hole is. */
								hole_low  = MAX( sect->floor, sectors[sect->neighbors[s]].floor );
								hole_high = MIN( sect->ceil,  sectors[sect->neighbors[s]].ceil  );
							}
							/* Check whether we're bumping into a wall. */
							if(hole_high < player.where.z + HEADMARGIN
									|| hole_low  > player.where.z-eyeheight + KNEEHEIGHT)
							{
								/* Bumps into a wall! Slide along the wall. */
								/* This formula is from Wikipedia article "vector projection". */
								float xd = sect->vertex[s+1].x - sect->vertex[s+0].x;
								float yd = sect->vertex[s+1].y - sect->vertex[s+0].y;
								player.velocity.x = xd * (dx*xd + dy*yd) / (xd*xd + yd*yd);
								player.velocity.y = yd * (dx*xd + dy*yd) / (xd*xd + yd*yd);
								moving = 0;
							}
						}
					MovePlayer(player.velocity.x, player.velocity.y);
					falling = 1;
				}

				while(SDL_PollEvent(&ev))
				{
					switch(ev.type)
					{
						case SDL_KEYDOWN:
						case SDL_KEYUP:
							switch(ev.key.keysym.sym)
							{
								case 'w': wsad[0] = ev.type==SDL_KEYDOWN; break;
								case 's': wsad[1] = ev.type==SDL_KEYDOWN; break;
								case 'a': wsad[2] = ev.type==SDL_KEYDOWN; break;
								case 'd': wsad[3] = ev.type==SDL_KEYDOWN; break;
								case 'q': goto done;
								case ' ': /* jump */
										  if(ground) { player.velocity.z += 0.5; falling = 1; }
										  break;
								case SDLK_LCTRL: /* duck */
								case SDLK_RCTRL: ducking = ev.type==SDL_KEYDOWN; falling=1; break;
								case SDLK_TAB: map = ev.type==SDL_KEYDOWN; break;
								default: break;
							}
							break;
						case SDL_QUIT: goto done;
					}
				}

				/* mouse aiming */
				/**/{   int x,y;
					SDL_GetRelativeMouseState(&x,&y);
					player.angle += x * 0.03f;
					yaw          = CLAMP(yaw - y*0.05f, -5, 5);
					player.yaw   = yaw - player.velocity.z*0.5f;
					MovePlayer(0,0); }/**/

				float move_vec[2] = {0.f, 0.f};
				if(wsad[0]) { move_vec[0] += player.anglecos*0.2f; move_vec[1] += player.anglesin*0.2f; }
				if(wsad[1]) { move_vec[0] -= player.anglecos*0.2f; move_vec[1] -= player.anglesin*0.2f; }
				if(wsad[2]) { move_vec[0] += player.anglesin*0.2f; move_vec[1] -= player.anglecos*0.2f; }
				if(wsad[3]) { move_vec[0] -= player.anglesin*0.2f; move_vec[1] += player.anglecos*0.2f; }
				int pushing = wsad[0] || wsad[1] || wsad[2] || wsad[3];
				float acceleration = pushing ? 0.4 : 0.2;

				player.velocity.x = player.velocity.x * (1-acceleration) + move_vec[0] * acceleration;
				player.velocity.y = player.velocity.y * (1-acceleration) + move_vec[1] * acceleration;

				//fprintf(fp, "%g %g %d %d %d %d %d %g %g\n", player.velocity.x, player.velocity.y, pushing, ducking, falling, moving, ground, player.angle, yaw); fflush(fp);
				//fscanf(fp, "%g %g %d %d %d %d %d %g %g\n", &player.velocity.x, &player.velocity.y, &pushing,&ducking,&falling,&moving,&ground, &player.angle, &yaw); MovePlayer(0,0);

				if(pushing) moving = 1;

				SDL_Delay(10);
			}
done:
			UnloadData();
			SDL_Quit();
			(void)argc;
			(void)argv;
			return 0;
		}
