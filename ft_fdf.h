/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:11:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/30 05:52:08 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <pthread.h>
# include <math.h>
# include <sys/time.h>

typedef struct			s_color_mlx
{
	int					red;
	int					green;
	int					blue;
}						t_color_mlx;

typedef struct			s_fractol
{
	struct s_win		*win;
	struct s_img		*img;
	int					iteration_max;
	double				zoom;
	double				move_x;
	double				move_y;
	double				zoom_i;
	double				zoom_r;
	int					alive;
	int					space;
	int					fractal;
	struct s_color_mlx	color_bg;
	struct s_color_mlx	color_pt;
	struct s_complex	z;
	int					menu;
	int					id;
}						t_fractol;

typedef struct			s_fdf_map
{
	int					key;
	wchar_t				*key_display;
	void				(*f)(t_fractol *fractol);
}						t_fdf_map;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_texture
{
	struct s_img		*img;
	char				*name;
}						t_texture;

typedef struct s_map
{
	char		*gnl;
	char		*get;
	int			fd;
	char		**map;
	char		**nb;
	int			**world;
	int			height;
	int			width;
}				t_map;

typedef struct 	s_player
{
	int 		move_up;
	int 		move_down;
	int 		move_left;
	int 		move_right;
	int 		life;
	double 		move_speed;
	double		rotate_speed;
	int 		in_menu_map;
	int 		in_menu_map_close;
	int			in_config;
	int			in_chat;
	int 		can_open;
	char		*message;
}				t_player;

typedef struct s_coucou
{
	struct s_win *win;
	struct s_vector pos;
	struct s_vector dir;
	struct s_vector plan;
	struct s_texture	**texture;
	int					texturepack;
	int		passage;
	struct s_img		*img;
	struct s_img		*bg;
	struct s_img		*settings;
	struct s_img		*xmap;
	struct s_img		*chat;
	struct s_img		*texture1;
	struct s_img		*texture2;
	struct s_img		*texture3;
	struct s_map		map;
	struct s_player		p;
	int					d;
}				t_coucou;

typedef struct			s_core
{
	struct s_coucou		*coucou;
	int					min;
	int					max;
}						t_core;

typedef struct	s_ray
{
	struct s_vector	pos;
	struct s_vector	dir;
	struct s_vector	plan;
	struct s_vector	raypos;
	struct s_vector	raydir;
	struct s_vector	sidedist;
	struct s_vector	deltadist;
	struct s_point	map;
	struct s_point	step;
	double 			camera;
	int				lineHeight;
	double			perpWallDist;
	int				h;
	int				Start;
	int				End;
	int				hit;
	int				side;
}				t_ray;



void	ft_wolf_init(char **argv);


/*
**
**
**
*/
void	ft_wolf_hooks_move_left(t_coucou *coucou);
void	ft_wolf_hooks_move_right(t_coucou *coucou);
void	ft_wolf_hooks_move_down(t_coucou *coucou);
void	ft_wolf_hooks_move_up(t_coucou *coucou);

/*
**
** FT_WOLF_HOOKS.c
**
*/

int		hooker2(t_coucou *coucou);
int		hooker(int k, t_coucou *coucou);
int		hooker_release(int k, t_coucou *coucou);
int		mouse_click(int keycode, int x, int y, t_coucou *coucou);

/*
**
** FT_WOLF_CALC.c
**
*/
void	calc(t_core *core);
void	calc2(t_coucou *coucou);
void	calc_menu(t_coucou *coucou);
void	ft_menu_chat(t_coucou *coucou);

/*
**
** FT_WOLF_RAY.c
**
*/

t_ray	set_ray_side(t_ray ray);
t_ray	init_ray(t_coucou *coucou, int x);


t_vector		create_vector(double x, double y);
t_vector		create_vector3d(double x, double y, double z);

double			ft_dpower(double n, size_t power);


void	ft_open_menu_config(t_coucou *coucou);


void	ft_wolf_display_texture_ground(int y, int min, int max, t_coucou *coucou);
void	ft_wolf_display_texture_stonebrick(int y, int min, int max, t_coucou *coucou, t_ray ray);
void	ft_wolf_display_texture_woodenplanks(int y, int min, int max, t_coucou *coucou, t_ray ray);
void	verLine(int y, int min, int max, t_color_mlx color, t_coucou *coucou);



unsigned int    get_fps(void);

void	ft_mlx_put_pixel_img(int x, int y, t_color_mlx color, struct s_img *img);
void	ft_mlx_draw_linept(t_point pt1, t_point pt2, struct s_img *img, t_color_mlx color);

#endif
