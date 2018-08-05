#ifndef FT_DOOMLIKE_H
# define FT_DOOMLIKE_H

# include <math.h>
# include <SDL/SDL.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

/*
**
**
** Define various vision related constants
**
** EYEHEIGHT	=> For the position of you're eye
** DUCKHEIGHT	=> For the position when you do the duck
** HEADMARGIN	=> This is the width of you're head
** KNEEHEIGHT	=> This is the width of you're knee (permit throw oject)
** HFOV 		=> This is the horizontal FOV
** VFOV 		=> This is the vertical FOV
**
**
** MaxVertices	=> This define allow a amount of vector to construct the map
** MaxEdges		=> This define allow a amount of vector to construct the sector
** MaxQueue		=> This define allow a max amount of portal on map
**
** DepthShading			=> This define allow shadow on map with dist
** VisibilityTracking	=> This define allow tracking pos on map
**
**
** min 					=> Return the min value between two number
** max 					=> Return the max value between two number
** abs 					=> Return the absolute value of number
** clamp				=> Return value in min and max
** sign					=> Return sign of value
** vxs					=> Return cross product of vector
**
*/

# define W						1920
# define H						1080
# define EYEHEIGHT				5.5
# define DUCKHEIGHT				2.5
# define HEADMARGIN				1
# define KNEEHEIGHT				2
# define MAXVERTICES			100
# define MAXEDGES				100
# define MAXQUEUE				32
# define HFOV					(1.0 * 0.73f * H / W)
# define VFOV					(1.0 * .2f)

# define MIN(a,b)				(((a) < (b)) ? (a) : (b))
# define MAX(a,b)				(((a) > (b)) ? (a) : (b))
# define ABS(a)					((a) < 0 ? -(a) : (a))
# define CLAMP(a, mi,ma)		MIN(MAX(a,mi),ma)
# define SIGN(v)				(((v) > 0) - ((v) < 0))
# define VXS(x0,y0, x1,y1)		((x0)*(y1) - (x1)*(y0))

# define DepthShading

# define VisibilityTracking

typedef struct		s_xy
{
	float			x;
	float			y;
}					t_xy;

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

typedef struct		s_sector
{
	float			floor;
	float			ceil;
	t_xy			*vertex;
	unsigned short	npoints;
	signed char		*neighbors;
# ifdef VisibilityTracking

	int				visible;
# endif
}					t_sector;

static t_sector		*sectors = NULL;

int					kappa(int argc, char **argv);

#endif
