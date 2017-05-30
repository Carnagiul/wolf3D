/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:34:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/30 04:26:55 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	p.in_config = 0;
	p.can_open = 0;
	return (p);
}

t_texture	**texturepack(t_win *win)
{
	t_file	*files;
	char	*path;
	char	*path2;
	int i;
	t_file	*content;
	int	j;
	t_texture	**texture;
	char		*name;
	int			count;

	i = 0;
	count = 0;
	path = ft_strdup("./textures/");
	texture = (t_texture **)malloc(sizeof(t_texture *) * ft_files_count_dir_wa(path));
	files = ft_create_array_dir_wa("./textures/");
	while (i < ft_files_count_dir_wa(path))
	{
		path2 = ft_string_join_path(path, files[i].name);
		content = ft_create_array_files_wa(path2);
		texture[i] = (t_texture *)malloc(sizeof(t_texture) * ft_files_count_files_wa(path2));
		j = 0;
		while (j < ft_files_count_files_wa(path2))
		{
			name = ft_strjoin(path2, "/");
			name = ft_strjoin(name, content[j].name);
			texture[i][j].img = ft_mlx_extended_gen_imgxpm(win, name);
			texture[i][j].name = ft_strdup(content[j].name);
			count++;
			j++;
		}
		free(path2);
		free(content);
		i++;
	}
	free(path);
	free(files);
	ft_printf("%d texture loaded in %d texturepack\n", count, i);
	return (texture);
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
	coucou.pos = create_vector(1.25, 1.26);
	coucou.dir = create_vector(-1, 0);
	coucou.plan = create_vector(0, 0.66);
	coucou.img = ft_mlx_extended_gen_img(coucou.win);
	coucou.map = ft_gen_world(argv[1]);
	coucou.p = ft_gen_player();
	coucou.texture = texturepack(coucou.win);
	coucou.texturepack = 0;
	if (ft_strcmp(coucou.texture[coucou.texturepack][0].name, "door.xpm") == 0)
		coucou.texture3 = coucou.texture[coucou.texturepack][0].img;
	else
		coucou.texture3 = coucou.texture[coucou.texturepack][1].img;
	if (ft_strcmp(coucou.texture[coucou.texturepack][0].name, "door.xpm") == 0)
		coucou.texture2 = coucou.texture[coucou.texturepack][1].img;
	else
		coucou.texture2 = coucou.texture[coucou.texturepack][0].img;
	coucou.settings = ft_mlx_extended_gen_imgxpm(coucou.win, "./texture_win/settings.xpm");
	coucou.xmap = ft_mlx_extended_gen_imgxpm(coucou.win, "./texture_win/map.xpm");
	coucou.d = d[0];
	ft_printf("c\nc\nc\n");
	mlx_hook(win->win, 2, (1L << 0), hooker, &coucou);
	mlx_hook(win->win, 4, (1L << 2), mouse_click, &coucou);
	mlx_hook(win->win, 3, (1L << 1), hooker_release, &coucou);

	mlx_loop_hook (win->mlx, hooker2, &coucou);
	mlx_loop(win->mlx);
}
