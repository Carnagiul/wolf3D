/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:12:38 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/23 22:21:57 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_move(t_coucou *coucou)
{
	if (coucou->p.move_up == 1)
		ft_wolf_hooks_move_up(coucou);
	if (coucou->p.move_down == 1)
		ft_wolf_hooks_move_down(coucou);
	if (coucou->p.move_right == 1)
		ft_wolf_hooks_move_right(coucou);
	if (coucou->p.move_left == 1)
		ft_wolf_hooks_move_left(coucou);
}

void	ft_wolf_in_menu(t_coucou *coucou)
{
	coucou->p.move_up = 0;
	coucou->p.move_down = 0;
	coucou->p.move_right = 0;
	coucou->p.move_left = 0;
	if (coucou->p.in_config == 1)
		ft_open_menu_config(coucou);
	else if (coucou->p.in_menu_map == 1)
		calc_menu(coucou);
	else if (coucou->p.in_inventory == 1)
		ft_menu_inv(coucou);
	else
		calc2(coucou);
}

void	ft_wolf_display(t_coucou *coucou)
{
	int	i;

	i = -1;
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win,
			coucou->img->img_ptr, 0, 0);
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win,
			coucou->xmap->img_ptr, (coucou->win->width -
				coucou->xmap->width), (coucou->win->height -
					coucou->xmap->height));
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win,
			coucou->settings->img_ptr, (coucou->win->width -
				coucou->settings->width), 0);
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win,
			coucou->chat->img_ptr, 0, 0);
	while (++i < 20)
	{
		if (coucou->p.life <= coucou->life[i]->max &&
				coucou->life[i]->min <= coucou->p.life)
		{
			mlx_put_image_to_window(coucou->win->mlx, coucou->win->win,
				coucou->life[i]->img->img_ptr, 0,
				coucou->win->height - coucou->life[i]->img->height);
		}
	}
	ft_menu_inv(coucou);
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
	ft_wolf_move(coucou);
	mlx_clear_window(coucou->win->mlx, coucou->win->win);
	if (player_is_in_menu(coucou) == 1)
		ft_wolf_in_menu(coucou);
	else
		calc2(coucou);
	ft_wolf_display(coucou);
	if (coucou->p.in_chat == 1)
		ft_menu_chat(coucou);
	ft_printf("\033[1A\033[Kfps: %d\n", get_fps());
	if (coucou->play_sound == 1)
		coucou->playlist = ft_playlist_play(coucou->playlist);
	if (coucou->p.life <= 0)
		ft_wolf_hooks_exit(coucou);
	return (0);
}
