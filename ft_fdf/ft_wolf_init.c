/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:34:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/29 03:39:23 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	ratio = (double)coucou->texture2->height / (double)dat;
	add = 0;
	double wallX; //where exactly the wall was hit
	if (ray.side == 0) wallX = ray.raypos.y + ray.perpWallDist * ray.raydir.y;
	else           wallX = ray.raypos.x + ray.perpWallDist * ray.raydir.x;
	wallX -= floor((wallX));
	int texX = (int)(wallX * (double)coucou->texture2->width);

	if(ray.side == 0 && ray.raydir.x > 0) texX = coucou->texture2->width - texX - 1;
	if(ray.side == 1 && ray.raydir.y < 0) texX = coucou->texture2->width - texX - 1;

	while (min < max)
	{
		int texY = (int)add * coucou->texture2->size_line;
		texturechute = texY + texX * 4;
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
	ratio = (double)coucou->texture3->height / (double)dat;
	add = 0;
	double wallX; //where exactly the wall was hit
	if (ray.side == 0) wallX = ray.raypos.y + ray.perpWallDist * ray.raydir.y;
	else           wallX = ray.raypos.x + ray.perpWallDist * ray.raydir.x;
	wallX -= floor((wallX));
	int texX = (int)(wallX * (double)coucou->texture3->width);

	if(ray.side == 0 && ray.raydir.x > 0) texX = coucou->texture3->width - texX - 1;
	if(ray.side == 1 && ray.raydir.y < 0) texX = coucou->texture3->width - texX - 1;

	while (min < max)
	{
		int texY = (int)add * coucou->texture3->size_line;
		texturechute = texY + texX * 4;
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

void	verLine(int y, int min, int max, t_color_mlx color, t_coucou *coucou)
{
	int chute;
	int red;
	int green;
	int blue;

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

		ray.hit = 0; //was there a wall hit?
		ray.side = 0; //was a NS or a EW wall hit?
		while (ray.hit == 0)
		{
			if (ray.sidedist.x < ray.sidedist.y)
			{
				ray.sidedist.x += ray.deltadist.x;
				ray.map.x += ray.step.x;
				ray.side = 0;
			}
			else
			{
				ray.sidedist.y += ray.deltadist.y;
				ray.map.y += ray.step.y;
				ray.side = 1;
			}
			if (core->coucou->map.world[ray.map.x][ray.map.y] > 0) ray.hit = 1;
		}
		if (ray.side == 0) ray.perpWallDist = (ray.map.x - ray.raypos.x + (1 - ray.step.x) / 2) / ray.raydir.x;
		else           ray.perpWallDist = (ray.map.y - ray.raypos.y + (1 - ray.step.y) / 2) / ray.raydir.y;

		ray.lineHeight = (int)(h / ray.perpWallDist);

		int drawStart = -ray.lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = ray.lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;

		if (drawStart > 0)
			verLine(x, 0, drawStart, create_color(0x00, 0xFF, 0xFF), core->coucou);
		if (drawEnd < h)
			verLine(x, drawStart, h, create_color(0x99, 0x99, 0x99), core->coucou);
		if (ray.side == 0)
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
	pthread_t	thread[4];
	t_core		core[4];
	int			i;
	int			max;

	i = -1;
	max = coucou->win->width / 4;
	while (++i < 4)
	{
		core[i].coucou = coucou;
		core[i].min = max * i;
		core[i].max = max * (i + 1);
		pthread_create(&thread[i], NULL, (void*)calc, &core[i]);
	}
	i = 0;
	while (i < 4)
		pthread_join(thread[i++], NULL);
}

int		hooker2(t_coucou *coucou)
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
	//ft_printf("\033[3A\033[Kfps: %d\nX: %d\nY: %d\n", get_fps(), (int)coucou->pos.x, (int)coucou->pos.y);
	return (0);
}

int		hooker(int k, t_coucou *coucou)
{

	if (coucou->p.in_menu_map == 0)
	{
		if (k == 126 || k == 13)
			coucou->p.move_up = 1;
		if (k == 125 || k == 1)
			coucou->p.move_down = 1;
		if (k == 124 || k == 2)
			coucou->p.move_left = 1;
		if (k == 123 || k == 0)
			coucou->p.move_right = 1;
		if (k == 49)
			coucou->p.move_speed = 0.2;
		if (k == 46)
			coucou->p.in_menu_map = 1;
		if (k == 69 && coucou->p.can_open == 1)
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
	coucou->p.can_open = 0;
	hooker2(coucou);
	return (1);
}

int		hooker_release(int k, t_coucou *coucou)
{
	if (coucou->p.in_menu_map == 0)
	{
		if (k == 126 || k == 13)
			coucou->p.move_up = 0;
		if (k == 125 || k == 1)
			coucou->p.move_down = 0;
		if (k == 124 || k == 2)
			coucou->p.move_left = 0;
		if (k == 123 || k == 0)
			coucou->p.move_right = 0;
		if (k == 49)
			coucou->p.move_speed = 0.1;
		coucou->p.in_menu_map_close = 0;
	}
	else
	{
		if (k == 46)
			coucou->p.in_menu_map_close = 1;
	}
	hooker2(coucou);
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
	coucou.texture3 = ft_mlx_extended_gen_imgxpm(coucou.win, "textures/yolo.xpm");
	coucou.map = ft_gen_world(argv[1]);
	coucou.p = ft_gen_player();
	ft_printf("c\nc\nc\n");
	mlx_hook(win->win, 2, (1L << 0), hooker, &coucou);
	mlx_hook(win->win, 3, (1L << 1), hooker_release, &coucou);

	mlx_loop_hook (win->mlx, hooker2, &coucou);
	mlx_loop(win->mlx);
}
