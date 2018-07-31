typedef struct	s_doom_win
{
	int			height;
	int			width;
	int			w2;
}				t_doom_win;

typedef struct	s_doom_camera
{
	float		eye;
	float		crouch;
	float		head_size;
	float		feet_size;
}				t_doom_camera;

typedef struct	s_doom_fov
{
	float		horizontal;
	float		vertival;
}				t_doom_fov;

#define Texture
#define Depth
#define Light
#define Visibility
#define Split

#define min(a,b) (a < b) ? a : b
#define max(a,b) (a > b) ? a : b
#define abs(a) (a < 0) ? -a : a

#define clamp(a, mi, ma) min(max(a,mi), ma)
#define sign(a) (a > 0) - (a < 0)
#define vxs(x0,y0,x1,y1) (x0*y1) - (x1*y0)
#define Overlap(a0,a1,b0,b1) (min(a0,a1) <= max(b0,b1) && (min(b0,b1) <= max(b0,b1))
#define IntersectBox(x0,y0,x1,y1,x2,y2,x3,y3) Overlap(x0,x1,x2,x3) && Overlap(y1,y2,y3,y4)
