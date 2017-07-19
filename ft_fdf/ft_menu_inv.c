/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_inv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 07:27:59 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 08:57:04 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_menu_inv(t_coucou *coucou)
{
	int		x;
	int		y;
	int		split;
	int		id;

	id = 0;
	split = coucou->win->width / 6;
	y = (coucou->win->height / 10) * 9;
	if (coucou->inventory)
	{
		if (coucou->inventory->actual_slot >= 1)
		{
			x = split * 1;
			mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->inventory->slot1->texture->img->img_ptr, x, y);
		}
		if (coucou->inventory->actual_slot >= 2)
		{
			x = split * (2);
			mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->inventory->slot2->texture->img->img_ptr, x, y);
		}
		if (coucou->inventory->actual_slot >= 3)
		{
			x = split * (3);
			mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->inventory->slot3->texture->img->img_ptr, x, y);
		}
		if (coucou->inventory->actual_slot >= 4)
		{
			x = split * (4);
			mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->inventory->slot4->texture->img->img_ptr, x, y);
		}
		if (coucou->inventory->actual_slot >= 5)
		{
			x = split * (5);
			mlx_put_image_to_window(coucou->win->mlx, coucou->win->win, coucou->inventory->slot5->texture->img->img_ptr, x, y);
		}
	}
}
