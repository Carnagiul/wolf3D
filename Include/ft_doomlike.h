#ifndef FT_DOOMLIKE_H
# define FT_DOOMLIKE_H

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

# define DOOM_DEBUG_PLAYER		1

typedef struct	s_vertex_3d
{
	float		x;
	float		y;
	float		z;
}				t_vertex_3d;

typedef struct	s_vertex_2d
{
	float		x;
	float		y;
}				t_vertex_2d;

typedef struct	s_doom_player
{
	char		*name;
	t_vertex_3d	*pos;
	t_vertex_3d	*speed;
}				t_doom_player;


void				ft_doom_rename_player(char *name, t_doom_player *player);
t_doom_player		*ft_doom_create_player(char *name);

int					kappa(int argc, char **argv);

#endif
