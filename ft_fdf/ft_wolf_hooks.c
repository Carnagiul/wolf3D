/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:12:38 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/04 02:43:05 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_fdf_map.h"

void	free_t_win(t_win *win)
{
	free(win->win);
	free(win->mlx);
	free(win);
}

void	free_t_img(t_img *img, t_win *win)
{
	mlx_destroy_image(win->mlx, img->img_ptr);
	free(img);
}

void	free_texture(t_texture **texture)
{
	int		i;
	int		j;
	char	*path;
	char	*path2;
	t_file	*files;

	i = 0;
	path = ft_strdup("./textures/");
	files = ft_create_array_dir_wa(path);
	while (i < ft_files_count_dir_wa(path))
	{
		path2 = ft_string_join_path(path, files[i].name);
		j = 0;
		while (j < ft_files_count_dir_wa(path2))
		{
			j++;
			free(texture[i][j].img);
			free(texture[i][j].name);
		}
		free(files[i].name);
		free(texture[i]);
		free(path2);
		i++;
	}
	free(files);
	free(path);
	free(texture);
}

void	free_map(t_map map)
{
	int i;

	free(map.gnl);
	free(map.get);
	i = 0;
	while (i < map.height)
	{
		if (map.map[i])
			free(map.map[i]);
		if (map.nb[i])
			free(map.nb[i]);
		if (map.world[i])
			free(map.world[i]);
		i++;
	}
	if (map.map)
		free(map.map);
	if (map.nb)
		free(map.nb);
	if (map.world)
		free(map.world);
}

void	exit_prgm(t_coucou *coucou)
{
	exit(0);
	(void)coucou;
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
	if (coucou->p.in_menu_map == 1 || coucou->p.in_config == 1 || coucou->p.in_chat == 1)
	{
		coucou->p.move_up = 0;
		coucou->p.move_down = 0;
		coucou->p.move_right = 0;
		coucou->p.move_left = 0;
		if (coucou->p.in_config == 1)
			ft_open_menu_config(coucou);
		else if (coucou->p.in_menu_map == 1)
			calc_menu(coucou);
		else
			calc2(coucou);
	}
	else
		calc2(coucou);
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->img->img_ptr, 0, 0);
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->xmap->img_ptr, (coucou->win->width - coucou->xmap->width), (coucou->win->height - coucou->xmap->height));
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->settings->img_ptr, (coucou->win->width - coucou->settings->width), 0);
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->chat->img_ptr, 0, 0);
	if (coucou->p.in_chat == 1)
		ft_menu_chat(coucou);
	//ft_printf("\033[2A\033[Kfps: %d\nchat: %s\n", get_fps(), coucou->p.message);
	return (0);
}

void	update_texture(t_coucou *coucou)
{
	if (ft_strcmp(coucou->texture[coucou->texturepack][0]->name, "door.xpm") == 0)
		coucou->texture3 = coucou->texture[coucou->texturepack][0]->img;
	else
		coucou->texture3 = coucou->texture[coucou->texturepack][1]->img;
	if (ft_strcmp(coucou->texture[coucou->texturepack][0]->name, "door.xpm") == 0)
		coucou->texture2 = coucou->texture[coucou->texturepack][1]->img;
	else
		coucou->texture2 = coucou->texture[coucou->texturepack][0]->img;
}

int		hooker(int k, t_coucou *coucou)
{
	if (k == 53)
		exit_prgm(coucou);
	if (coucou->p.in_menu_map == 0 && coucou->p.in_config == 0 && coucou->p.in_chat == 0)
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
		if (k >= 82 && k <= 85)
		{
			if (k == 82)
				coucou->texturepack = 0;
			if (k == 83)
				coucou->texturepack = 1;
			if (k == 84)
				coucou->texturepack = 2;
			if (k == 85)
				coucou->texturepack = 3;
			update_texture(coucou);
		}
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
	else if (coucou->p.in_config == 1)
	{
		if (k == 126 || k == 13)
			coucou->texturepack -= (coucou->texturepack > 0) ? 1 : 0;
		if (k == 125 || k == 1)
		{
			//coucou->texturepack += (coucou->texturepack < ft_files_count_dir_wa("./textures/")) ? 1 : 0;
			if (coucou->texturepack + 1< ft_files_count_dir_wa("./textures/"))
				coucou->texturepack += 1;
		}
		update_texture(coucou);
	}
	coucou->p.can_open = 0;
	hooker2(coucou);
	return (1);
}

int		hooker_release(int k, t_coucou *coucou)
{
	if (coucou->p.in_menu_map == 0 && coucou->p.in_config == 0 && coucou->p.in_chat == 0)
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
	}
	if (coucou->p.in_chat == 1)
	{
		int i;
		int	j;

		j = 0;
		i = 0;
		while (i < 38)
		{
			if (k == g_t_keycode[i].keycode)
			{
				coucou->p.message = ft_free_join1(coucou->p.message, g_t_keycode[i].key);
				i = 38;
				j = 1;
			}
			i++;
		}
		ft_printf("\033[1A\033[Kchat: %s\n", coucou->p.message);
		if (k == 76 && j == 0)
		{
			ft_printf("\033[1A\033[K%s say: @R%s@@\n\n", "George", coucou->p.message);
			free(coucou->p.message);
			coucou->p.message = ft_strdup("");
		}
	}
	hooker2(coucou);
	return (1);
}

int		mouse_click(int keycode, int x, int y, t_coucou *coucou)
{
	if (keycode == 1)
	{
		if (x >= (coucou->win->width - coucou->xmap->width) && y >= (coucou->win->height - coucou->xmap->height))
		{
			coucou->p.in_menu_map = (coucou->p.in_menu_map == 0) ? 1 : 0;
			coucou->p.in_config = 0;
			coucou->p.in_chat = 0;
		}
		if (x >= (coucou->win->width - coucou->settings->width) && y <= (coucou->settings->height))
		{
			coucou->p.in_config = (coucou->p.in_config == 0) ? 1 : 0;
			coucou->p.in_menu_map = 0;
			coucou->p.in_chat = 0;
		}
		if (x <= coucou->chat->width  && y <= (coucou->chat->height))
		{
			coucou->p.in_chat = (coucou->p.in_chat == 0) ? 1 : 0;
			coucou->p.in_menu_map = 0;
			coucou->p.in_config = 0;
		}
	}
	hooker2(coucou);
	return (1);
}
