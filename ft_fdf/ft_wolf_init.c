/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:34:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/05 20:07:40 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_display_texture(t_point pts[2], t_ray ray, t_img *img,
		t_img *texture)
{
	int		tab[5];
	double	tab2[3];

	tab[0] = pts[1].x - pts[0].x;
	tab2[1] = (double)texture->height / tab[0];
	tab2[0] = 0;
	tab2[2] = (ray.side == 0) ? ray.raypos.y + ray.perpWallDist * ray.raydir.y :
		ray.raypos.x + ray.perpWallDist * ray.raydir.x;
	tab2[2] -= floor(tab2[2]);
	tab[1] = (int)(tab2[2] * (double)texture->width);
	if ((ray.side == 0 && ray.raydir.x > 0) ||
			(ray.side == 1 && ray.raydir.y < 0))
		tab[1] = texture->width - tab[1] - 1;
	while (pts[0].x < pts[1].x)
	{
		tab[2] = (int)tab2[0] * texture->size_line;
		tab[3] = tab[2] + (tab[1] * 4);
		tab2[0] += tab2[1];
		tab[4] = (pts[0].y * 4) + (pts[0].x * img->size_line);
		img->img[tab[4]] = texture->img[tab[3]];
		img->img[++tab[4]] = texture->img[++tab[3]];
		img->img[++tab[4]] = texture->img[++tab[3]];
		pts[0].x++;
	}
}

t_map	ft_gen_world(char *name)
{
	t_map map;

	int		i;
	int		j;

	map.get = ft_strnew(1);
	map.fd = open(name, O_RDONLY);
	i = 0;
	while (get_next_line(map.fd, &(map.gnl)) >= 1)
	{
		map.get = ft_free_join1(map.get, map.gnl);
		map.get = ft_free_join1(map.get, "\n");
		ft_strdel(&(map.gnl));
		i++;
	}
	close(map.fd);
	map.world = (int **)malloc(sizeof(int *) * i);
	map.height = i;
	map.width = 0;
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
		j = 0;
		while (map.nb[j])
			free(map.nb[j++]);
		free(map.nb);
		i++;
	}
	free(map.get);
	free(map.gnl);
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
	p.in_chat = 0;
	p.can_open = 0;
	p.message = ft_strdup("");
	return (p);
}

t_texture	***texturepack(t_win *win)
{
	t_file	*files;
	char	*path;
	char	*path2;
	int i;
	t_file	*content;
	int	j;
	t_texture	***texture;
	char		*name;
	int			count;

	i = 0;
	count = 0;
	path = ft_strdup("./textures/");
	texture = (t_texture ***)malloc(sizeof(t_texture **) * ft_files_count_dir_wa(path));
	files = ft_create_array_dir_wa("./textures/");
	while (i < ft_files_count_dir_wa(path))
	{
		path2 = ft_string_join_path(path, files[i].name);
		content = ft_create_array_files_wa(path2);
		texture[i] = (t_texture **)malloc(sizeof(t_texture *) * ft_files_count_files_wa(path2));
		j = 0;
		while (j < ft_files_count_files_wa(path2))
		{
			name = ft_strjoin(path2, "/");
			name = ft_free_join1(name, content[j].name);
			texture[i][j] = (t_texture *)malloc(sizeof(t_texture));
			texture[i][j]->name = content[j].name;
			texture[i][j]->img = ft_mlx_extended_gen_imgxpm(win, name);
			free(content[j].name);
			free(name);
			count++;
			j++;
		}
		free(files[i].name);
		free(path2);
		free(content);
		i++;
	}
	free(path);
	free(files);
	ft_printf("%d texture loaded in %d texturepack\n", count, i);
	return (texture);
}

void	ft_wolf_init2(char **argv)
{
	int		i;
	char	*ret;

	i = 1;
	while (argv[i])
		i++;
	if (i < 2)
	{
		ft_printf("Error: ./wolf3d <filename.wolf3d> [-username]\n");
		exit(0);
	}
	ret = ft_get_extension(argv[1]);
	if (ft_strcmp(ret, "wolf3d") != 0)
	{
		ft_printf("Error: ./wolf3d <filename.wolf3d> [-username]\n");
		exit(0);
	}
	free(ret);
}

void	ft_wolf_init(char **argv)
{
	int		d[2];
	t_coucou *coucou;

	d[0] = 1280;
	d[1] = 720;
	ft_wolf_init2(argv);
	coucou = (t_coucou *)malloc(sizeof(t_coucou));
	coucou->win = ft_mlx_extended_gen_win(d[0], d[1], "wolf piquerue");
	coucou->passage = 0;
	coucou->pos = create_vector(1.25, 1.26);
	coucou->dir = create_vector(-1, 0);
	coucou->plan = create_vector(0, 0.66);
	coucou->img = ft_mlx_extended_gen_img(coucou->win);
	coucou->map = ft_gen_world(argv[1]);
	coucou->p = ft_gen_player();
	coucou->texture = texturepack(coucou->win);
	coucou->texturepack = 0;
	update_texture(coucou);
	coucou->settings = ft_mlx_extended_gen_imgxpm(coucou->win, "./texture_win/settings.xpm");
	coucou->xmap = ft_mlx_extended_gen_imgxpm(coucou->win, "./texture_win/map.xpm");
	coucou->chat = ft_mlx_extended_gen_imgxpm(coucou->win, "./texture_win/chat.xpm");
	coucou->d = d[0];
	ft_printf("c\nc\n");
	mlx_hook(coucou->win->win, 2, (1L << 0), hooker, coucou);
	mlx_hook(coucou->win->win, 4, (1L << 2), mouse_click, coucou);
	mlx_hook(coucou->win->win, 3, (1L << 1), hooker_release, coucou);
	mlx_hook(coucou->win->win, 17, (1L << 17), red_cross, coucou);
	mlx_loop_hook(coucou->win->mlx, hooker2, coucou);
	mlx_loop(coucou->win->mlx);
}
