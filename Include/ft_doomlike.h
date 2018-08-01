#ifndef FT_DOOMLIKE_H
# define FT_DOOMLIKE_H

#include <math.h>
#include <signal.h>
#include <assert.h>


/* Define window size */
# define W2				640
# define W				640
# define H				480

/*
**
**
** Define various vision related constants
**
** EyeHeight	=> for the position of you're eye
** DuckHeight	=> for the position when you do the duck
** HeadMargin	=> This is the width of you're head
** KneeHeight	=> This is the width of you're knee (permit throw oject)
** hfov 		=> This is the horizontal FOV
** vfov 		=> This is the vertical FOV
**
**
** MaxVertices	=> This define allow a amount of vector to construct the map
** MaxEdges		=> This define allow a amount of vector to construct the sector
** MaxQueue		=> This define allow a max amount of portal on map
**
** TextureMapping		=> This define allow texture on map
** DepthShading			=> This define allow shadow on map with dist
** LightMapping			=> This define allow lights on map (VERY DANGEROUS)
** VisibilityTracking	=> This define allow tracking pos on map
** SplitScreen			=> This define allow two player
**
*/

# define EyeHeight		6
# define DuckHeight		2.5
# define HeadMargin		1
# define KneeHeight		2

# define hfov (1.0 * 0.73f * H/W)
# define vfov (1.0 * .2f)

# define MaxVertices	100
# define MaxEdges		100
# define MaxQueue		32

# define TextureMapping
# define DepthShading
# define LightMapping
# define VisibilityTracking
# define SplitScreen

/* Sectors: Floor and ceiling height; list of edge vertices and neighbors */

#ifdef TextureMapping
typedef int		Texture[1024][1024];

typedef struct	xy
{
	float		x;
	float		y;
}				xy;

typedef struct	xyz
{
	float		x;
	float		y;
	float		z;
}				xyz;

typedef struct	TextureSet
{
	Texture		texture;
	Texture		normalmap;
	Texture		lightmap;
	Texture		lightmap_diffuseonly;
}				TextureSet;
#endif

static struct	sector
{
	float			floor;
	float			ceil;
	struct xy		*vertex; // Each vertex has an x and y coordinate
	signed char		*neighbors;           // Each edge may have a corresponding neighboring sector
	unsigned		npoints;                 // How many vertexes there are
	#ifdef TextureMapping
	struct TextureSet		*floortexture;
	struct TextureSet		*ceiltexture;
	struct TextureSet		*uppertextures;
	struct TextureSet		*lowertextures;
	#endif
	#ifdef VisibilityTracking
	int				visible;
	#endif
}				*sectors = NULL;

static unsigned		NumSectors = 0;

#ifdef VisibilityTracking
# define MaxVisibleSectors 256
struct xy	VisibleFloorBegins[MaxVisibleSectors][W];
struct xy	VisibleFloorEnds[MaxVisibleSectors][W];
struct xy	VisibleCeilBegins[MaxVisibleSectors][W];
struct xy	VisibleCeilEnds[MaxVisibleSectors][W];
char		VisibleFloors[MaxVisibleSectors][W];
char		VisibleCeils[MaxVisibleSectors][W];
unsigned	NumVisibleSectors = 0;

typedef struct		s_doomlike_tracking
{
	struct xy	VisibleFloorBegins[MaxVisibleSectors][W];
	struct xy	VisibleFloorEnds[MaxVisibleSectors][W];
	struct xy	VisibleCielBegins[MaxVisibleSectors][W];
	struct xy	VisibleCielEnds[MaxVisibleSectors][W];
	char		VisibleFloors[MaxVisibleSectors][W];
	char		VisibleCiels[MaxVisibleSectors][W];
	unsigned	NumVisibleSectors;
}					t_doomlike_tracking;
#endif

#ifdef LightMapping
static struct light
{
	struct xyz		where;
	struct xyz		light;
	unsigned char	sector;
} *lights = NULL;
static unsigned NumLights = 0;
#endif

static SDL_Surface *surface = NULL;

/* Player: location */
static struct	player
{
    struct xyz		where;      // Current position
	struct xyz		velocity;   // Current motion vector
    float			angle;
	float			anglesin;
	float			anglecos;
	float			yaw;   // Looking towards (and sin() and cos() thereof)
    unsigned		sector;                        // Which sector the player is currently in
}				player;

// Utility functions. Because C doesn't have templates,
// we use the slightly less safe preprocessor macros to
// implement these functions that work with multiple types.
# define min(a,b)             (((a) < (b)) ? (a) : (b)) // min: Choose smaller of two scalars.
# define max(a,b)             (((a) > (b)) ? (a) : (b)) // max: Choose greater of two scalars.
# define clamp(a, mi,ma)      min(max(a,mi),ma)         // clamp: Clamp value into set range.
# define vxs(x0,y0, x1,y1)    ((x0)*(y1) - (x1)*(y0))   // vxs: Vector cross product
// Overlap:  Determine whether the two number ranges overlap.
# define Overlap(a0,a1,b0,b1) (min(a0,a1) <= max(b0,b1) && min(b0,b1) <= max(a0,a1))
// IntersectBox: Determine whether two 2D-boxes intersect.
# define IntersectBox(x0,y0, x1,y1, x2,y2, x3,y3) (Overlap(x0,x1,x2,x3) && Overlap(y0,y1,y2,y3))
// PointSide: Determine which side of a line the point is on. Return value: <0, =0 or >0.
# define PointSide(px,py, x0,y0, x1,y1) vxs((x1)-(x0), (y1)-(y0), (px)-(x0), (py)-(y0))
// Intersect: Calculate the point of intersection between two lines.
# define Intersect(x1,y1, x2,y2, x3,y3, x4,y4) ((struct xy) { \
    vxs(vxs(x1,y1, x2,y2), (x1)-(x2), vxs(x3,y3, x4,y4), (x3)-(x4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)), \
    vxs(vxs(x1,y1, x2,y2), (y1)-(y2), vxs(x3,y3, x4,y4), (y3)-(y4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)) })

int kappa(void);

#endif
