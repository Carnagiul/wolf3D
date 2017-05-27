/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:34:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/22 09:00:13 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <math.h>
#include <sys/time.h>
#define dcore 1

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct 	s_texture
{

}				t_texture;

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
	int 		can_open;
}				t_player;

typedef struct s_coucou
{
	struct s_win *win;
	struct s_vector pos;
	struct s_vector dir;
	struct s_vector plan;
	int		passage;
	struct s_img		*img;
	struct s_img		*bg;
	struct s_img		*texture1;
	struct s_img		*texture2;
	struct s_img		*texture3;
	struct s_map		map;
	struct s_player		p;
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
}				t_ray;

unsigned int    get_fps(void)
{
	static struct timeval    prev;
	static struct timeval    t;
	unsigned int             fps;

	gettimeofday(&t, NULL);
	fps = ((t.tv_sec * 1000000 + t.tv_usec) - (prev.tv_sec * 1000000 +
				prev.tv_usec));
	prev = t;
	return (1000000 / fps);
}

t_vector		create_vector(double x, double y)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	return (v);
}

void	ft_wolf_display_texture_ground(int y, int min, int max, t_coucou *coucou)
{
	int texturechute;
	int chute;

	while (min < max)
	{
		texturechute = ((y % coucou->texture1->height) * 4) + ((min % coucou->texture1->width) * coucou->texture1->size_line);
		chute = (y * 4) + (min * coucou->img->size_line);
		coucou->img->img[chute] = coucou->texture1->img[texturechute];
		coucou->img->img[++chute] = coucou->texture1->img[++texturechute];
		coucou->img->img[++chute] = coucou->texture1->img[++texturechute];
		min++;
	}
}

void	ft_wolf_display_texture_stonebrick(int y, int min, int max, t_coucou *coucou, t_ray ray)
{
	int texturechute;
	int chute;
	int dat;
	double ratio;
	double add;

	dat = max - min;
	if (dat > coucou->texture2->height)
		ratio = (double)coucou->texture2->width / (double)dat;
	else	
		ratio = (double)coucou->texture2->width / (double)dat;
	add = 0;
	while (min < max)
	{
		texturechute = ((((int)ray.raypos.y) % coucou->texture2->height) * 4) + ((int)add * coucou->texture2->size_line);
		add += ratio;
		chute = (y * 4) + (min * coucou->img->size_line);
		coucou->img->img[chute] = coucou->texture2->img[texturechute];
		coucou->img->img[++chute] = coucou->texture2->img[++texturechute];
		coucou->img->img[++chute] = coucou->texture2->img[++texturechute];
		min++;
	}
}

void	ft_wolf_display_texture_woodenplanks(int y, int min, int max, t_coucou *coucou, t_ray ray)
{
	int texturechute;
	int chute;
	int dat;
	double ratio;
	double add;

	dat = max - min;
	if (dat > coucou->texture3->height)
		ratio = (double)coucou->texture3->width / (double)dat;
	else	
		ratio = (double)coucou->texture3->width / (double)dat;
	add = 0;
	while (min < max)
	{
		texturechute = ((((int)ray.raypos.y) % coucou->texture3->height) * 4) + ((int)add * coucou->texture3->size_line);
		add += ratio;
		chute = (y * 4) + (min * coucou->img->size_line);
		coucou->img->img[chute] = coucou->texture3->img[texturechute];
		coucou->img->img[++chute] = coucou->texture3->img[++texturechute];
		coucou->img->img[++chute] = coucou->texture3->img[++texturechute];
		min++;
	}
	if (ray.sidedist.x <= 2 && ray.sidedist.y <= 2)
		coucou->p.can_open = 1;
}
/*
void	ft_wolf_display_texture(int y, int min, int max, t_coucou *coucou, int id)
{
	if (id == 0)
		ft_wolf_display_texture_ground(y, min, max, coucou);
	if (id == 1)
		ft_wolf_display_texture_stonebrick(y, min, max, coucou);
	if (id == 1)
		ft_wolf_display_texture_woodenplanks(y, min, max, coucou);

}
	scanf("%s", ret);
*/
void	verLine(int y, int min, int max, t_color_mlx color, t_coucou *coucou)
{
	int chute;
	int red;
	int green;
	int blue;

//	if (max == coucou->win->height)
//		ft_wolf_display_texture(y, min, max, coucou, 0);
//	else
//	{
		red = color.red;
		green = color.green;
		blue = color.blue;
		while (min < max)
		{
			chute = (y * 4) + (min * coucou->img->size_line);
			coucou->img->img[chute] = blue;
			coucou->img->img[++chute] = green;
			coucou->img->img[++chute] = red;
			coucou->img->img[++chute] = 0;
			min++;
		}
//	}
}

double	ft_dpower(double n, size_t power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (n);
	return (n * ft_dpower(n, power - 1));
}

t_ray	set_ray_side(t_ray ray)
{
	ray.step.x = (ray.raydir.x < 0) ? -1 : 1;
	if (ray.step.x == -1)
		ray.sidedist.x = (ray.raypos.x - ray.map.x) * ray.deltadist.x;
	else
		ray.sidedist.x = (ray.map.x + 1.0 - ray.raypos.x ) * ray.deltadist.x;
	ray.step.y = (ray.raydir.y < 0) ? -1 : 1;
	if (ray.step.y == -1)
		ray.sidedist.y = (ray.raypos.y - ray.map.y) * ray.deltadist.y;
	else
		ray.sidedist.y = (ray.map.y + 1.0 - ray.raypos.y) * ray.deltadist.y;
	return (ray);
}

t_ray	init_ray(t_coucou *coucou, int x)
{
	t_ray	ray;

	ray.pos = create_vector(coucou->pos.x, coucou->pos.y);
	ray.dir = create_vector(coucou->dir.x, coucou->dir.y);
	ray.plan = create_vector(coucou->plan.x, coucou->plan.y);
	ray.camera = 2 * x / (double)coucou->win->width - 1;
	ray.raypos = create_vector(ray.pos.x, ray.pos.y);
	ray.raydir = create_vector(ray.dir.x + ray.plan.x * ray.camera, ray.dir.y + ray.plan.y * ray.camera);
	ray.map.x = (int)ray.raypos.x;
	ray.map.y = (int)ray.raypos.y;
	ray.deltadist.x = sqrt(1 + (ft_dpower(ray.raydir.y, 2) / ft_dpower(ray.raydir.x, 2)));
	ray.deltadist.y = sqrt(1 + (ft_dpower(ray.raydir.x, 2) / ft_dpower(ray.raydir.y, 2)));
	ray = set_ray_side(ray);
	return (ray);
}

void	calc(t_core *core)
{
	t_ray	ray;
	t_color_mlx color;

	int h = core->coucou->win->height;
	for(int x = core->min; x < core->max; x++)
	{
		ray = init_ray(core->coucou, x);
		double perpWallDist;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		while (hit == 0)
		{
			if (ray.sidedist.x < ray.sidedist.y)
			{
				ray.sidedist.x += ray.deltadist.x;
				ray.map.x += ray.step.x;
				side = 0;
			}
			else
			{
				ray.sidedist.y += ray.deltadist.y;
				ray.map.y += ray.step.y;
				side = 1;
			}
			if (core->coucou->map.world[ray.map.x][ray.map.y] > 0) hit = 1;
		}
		if (side == 0) perpWallDist = (ray.map.x - ray.raypos.x + (1 - ray.step.x) / 2) / ray.raydir.x;
		else           perpWallDist = (ray.map.y - ray.raypos.y + (1 - ray.step.y) / 2) / ray.raydir.y;

		int lineHeight = (int)(h / perpWallDist);

		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;

		if (drawStart > 0)
			verLine(x, 0, drawStart, create_color(0x00, 0xFF, 0xFF), core->coucou);
		if (drawEnd < h)
			verLine(x, drawStart, h, create_color(0x99, 0x99, 0x99), core->coucou);
		if (side == 0)
			color = (ray.raydir.x >= 0) ? create_color(0xFF, 0, 0) : create_color(0x00, 0xFF, 0);
		else
			color = (ray.raydir.y >= 0) ? create_color(0, 0, 0xFF) : create_color(0xFF, 0, 0xFF);
		if (core->coucou->map.world[ray.map.x][ray.map.y] == 1)
			ft_wolf_display_texture_stonebrick(x, drawStart, drawEnd, core->coucou, ray);
		else if (core->coucou->map.world[ray.map.x][ray.map.y] == 2)
			ft_wolf_display_texture_woodenplanks(x, drawStart, drawEnd, core->coucou, ray);
		else 
			verLine(x, drawStart, drawEnd, color, core->coucou);
	}
}

void	calc2(t_coucou *coucou)
{
	pthread_t	thread[dcore];
	t_core		core[dcore];
	int			i;
	int			max;

	i = -1;
	max = coucou->win->width / dcore;
	while (++i < dcore)
	{
		core[i].coucou = coucou;
		core[i].min = max * i;
		core[i].max = max * (i + 1);
		pthread_create(&thread[i], NULL, (void*)calc, &core[i]);

	}
	i = 0;
	while (i < dcore)
		pthread_join(thread[i++], NULL);
}

void	ft_wolf_hooks_move_up(t_coucou *coucou)
{
	if(!coucou->map.world[(int)(coucou->pos.x + coucou->dir.x * coucou->p.move_speed)][(int)coucou->pos.y])
		coucou->pos.x += coucou->dir.x * coucou->p.move_speed;
	if(!coucou->map.world[(int)coucou->pos.x][(int)(coucou->pos.y + coucou->dir.y * coucou->p.move_speed)])
		coucou->pos.y += coucou->dir.y * coucou->p.move_speed;
}

void	ft_wolf_hooks_move_down(t_coucou *coucou)
{
	if(!coucou->map.world[(int)(coucou->pos.x - coucou->dir.x * coucou->p.move_speed)][(int)coucou->pos.y])
		coucou->pos.x -= coucou->dir.x * coucou->p.move_speed;
	if(!coucou->map.world[(int)coucou->pos.x][(int)(coucou->pos.y - coucou->dir.y * coucou->p.move_speed)])
		coucou->pos.y -= coucou->dir.y * coucou->p.move_speed;
}

void	ft_wolf_hooks_move_right(t_coucou *coucou)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = coucou->dir.x;
	coucou->dir.x = coucou->dir.x * cos(coucou->p.rotate_speed) - coucou->dir.y * sin(coucou->p.rotate_speed);
	coucou->dir.y = oldDirX * sin(coucou->p.rotate_speed) + coucou->dir.y * cos(coucou->p.rotate_speed);
	oldPlaneX = coucou->plan.x;
	coucou->plan.x = coucou->plan.x * cos(coucou->p.rotate_speed) - coucou->plan.y * sin(coucou->p.rotate_speed);
	coucou->plan.y = oldPlaneX * sin(coucou->p.rotate_speed) + coucou->plan.y * cos(coucou->p.rotate_speed);
}

void	ft_wolf_hooks_move_left(t_coucou *coucou)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = coucou->dir.x;
	coucou->dir.x = coucou->dir.x * cos(-coucou->p.rotate_speed) - coucou->dir.y * sin(-coucou->p.rotate_speed);
	coucou->dir.y = oldDirX * sin(-coucou->p.rotate_speed) + coucou->dir.y * cos(-coucou->p.rotate_speed);
	oldPlaneX = coucou->plan.x;
	coucou->plan.x = coucou->plan.x * cos(-coucou->p.rotate_speed) - coucou->plan.y * sin(-coucou->p.rotate_speed);
	coucou->plan.y = oldPlaneX * sin(-coucou->p.rotate_speed) + coucou->plan.y * cos(-coucou->p.rotate_speed);
}

int		hooker2(t_coucou *coucou)
{
	if (coucou->p.move_up + coucou->p.move_down + coucou->p.move_left + coucou->p.move_right >= 1)
{
		if (coucou->passage == 1)
		{
			mlx_destroy_image(coucou->win->mlx, coucou->img->img_ptr);
			free(coucou->img);
			coucou->img = ft_mlx_extended_gen_img(coucou->win);
		}
		coucou->passage = 1;
		mlx_clear_window(coucou->win->mlx, coucou->win->win);
		if (coucou->p.move_up == 1)
			ft_wolf_hooks_move_up(coucou);
		if (coucou->p.move_down == 1)
			ft_wolf_hooks_move_down(coucou);
		if (coucou->p.move_right == 1)
			ft_wolf_hooks_move_right(coucou);
		if (coucou->p.move_left == 1)
			ft_wolf_hooks_move_left(coucou);
		calc2(coucou);
		mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->img->img_ptr, 0, 0);
	}
	ft_printf("\033[3A\033[Kfps: %d\nX: %d\nY: %d\n", get_fps(), (int)coucou->pos.x, (int)coucou->pos.y);
	return (0);
}

int		hooker(int k, t_coucou *coucou)
{

	if (coucou->p.in_menu_map == 0)
	{
		if (k == 126 || k == 13 || k == 65362 || k == 122)
			coucou->p.move_up = 1;
		if (k == 125 || k == 1 || k == 65364 || k == 115)
			coucou->p.move_down = 1;
		if (k == 124 || k == 2 || k == 65363 || k == 100)
			coucou->p.move_left = 1;
		if (k == 123 || k == 0 || k == 65361 || k == 113)
			coucou->p.move_right = 1;
		if (k == 49)
			coucou->p.move_speed = 0.2;
		if (k == 46)
			coucou->p.in_menu_map = 1;
		if ((k == 69 || k == 101) && coucou->p.can_open == 1)
		{
			int x = (int)coucou->pos.x - 2;
			int y;
			while (x < (int)coucou->pos.x + 2)
			{
				y = (int)coucou->pos.y - 2;
				while (y < (int)coucou->pos.y + 2)
				{
					if (coucou->map.world[x][y] == 2)
						coucou->map.world[x][y] = 0;
					y++;
				}
				x++;
			}
		}
	}
	else
	{
		if (k == 46 && coucou->p.in_menu_map_close == 1)
			coucou->p.in_menu_map = 0;
	}
	//ft_printf("%d\n\n\n\n", k);
	coucou->p.can_open = 0;
	hooker2(coucou);
	//ft_printf("\033[3A\033[Kfps: %d\nX: %d\nY: %d\n", get_fps(), (int)coucou->pos.x, (int)coucou->pos.y);
	return (1);
}

int		hooker_release(int k, t_coucou *coucou)
{
//	ft_printf("HAHAHAHA CA FONCTIONNE PAS");
	if (coucou->p.in_menu_map == 0)
	{
		if (k == 126 || k == 13 || k == 65362 || k == 122)
			coucou->p.move_up = 0;
		if (k == 125 || k == 1 || k == 65364 || k == 115)
			coucou->p.move_down = 0;
		if (k == 124 || k == 2 || k == 65363 || k == 100)
			coucou->p.move_left = 0;
		if (k == 123 || k == 0 || k == 65361 || k == 113)
			coucou->p.move_right = 0;
		if (k == 49)
			coucou->p.move_speed = 0.1;
		coucou->p.in_menu_map_close = 0;
	}
	else
	{
	//	if (k == 46)
	//		coucou->p.in_menu_map_close = 1;
	}
	//ft_printf("%d\n\n\n\n", k);
	hooker2(coucou);
	//ft_printf("\033[3A\033[Kfps: %d\nX: %d\nY: %d\n", get_fps(), (int)coucou->pos.x, (int)coucou->pos.y);
	return (1);
}


t_map	ft_gen_world(char *name)
{
	t_map map;

	int		i;
	int		j;

	map.get = ft_strnew(1);
	map.gnl = ft_strnew(1);
	map.fd = open(name, O_RDONLY);
	i = 0;
	while (get_next_line(map.fd, &(map.gnl)) >= 1)
	{
		map.get = ft_free_join(map.get, map.gnl);
		map.get = ft_free_join1(map.get, "\n");
		map.gnl = ft_strnew(1);
		i++;
	}
	close(map.fd);
	map.world = (int **)malloc(sizeof(int *) * i);
	map.height = i;
	map.map = ft_strsplit(map.get, '\n');
	i = 0;
	while (map.map[i])
	{
		j = 0;
		map.nb = ft_strsplit(map.map[i], ' ');
		while (map.nb[j])
			j++;
		map.width = j;
		map.world[i] = (int *)malloc(sizeof(int) * j);
		j = 0;
		while (map.nb[j])
		{
			map.world[i][j] = ft_atoi(map.nb[j]);
			j++;
		}
		i++;
	}
	return (map);
}

t_player	ft_gen_player(void)
{
	t_player p;

	p.move_up = 0;
	p.move_down = 0;
	p.move_left = 0;
	p.move_right = 0;
	p.move_speed = 0.1;
	p.rotate_speed = 0.05;
	p.in_menu_map = 0;
	p.in_menu_map_close = 0;
	p.can_open = 0;
	return (p);
}

void	ft_wolf_init(char **argv)
{
	t_win *win;
	int		d[2];
	t_coucou coucou;

	d[0] = 1280;
	d[1] = 720;
	win = ft_mlx_extended_gen_win(d[0], d[1], "wolf piquerue");
	coucou.win = win;
	coucou.passage = 0;
	coucou.pos = create_vector(20, 7);
	coucou.dir = create_vector(-1, 0);
	coucou.plan = create_vector(0, 0.66);
	coucou.img = ft_mlx_extended_gen_img(coucou.win);
	coucou.texture1 = ft_mlx_extended_gen_imgxpm(coucou.win, "textures/texture_sand.xpm");
	coucou.texture2 = ft_mlx_extended_gen_imgxpm(coucou.win, "textures/brick.xpm");
	coucou.texture3 = ft_mlx_extended_gen_imgxpm(coucou.win, "textures/door2.xpm");
	coucou.map = ft_gen_world(argv[1]);
	coucou.p = ft_gen_player();
	ft_printf("c\nc\nc\n");
	mlx_hook(win->win, 2, (1L << 0), hooker, &coucou);
	mlx_hook(win->win, 3, (1L << 1), hooker_release, &coucou);

	mlx_loop_hook (win->mlx, hooker2, &coucou);
	mlx_loop(win->mlx);
}
