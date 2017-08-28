/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_inv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 07:27:59 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/23 22:18:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_menu_inv2(t_coucou *coucou, t_item *item, int x, int y)
{
	mlx_put_image_to_window(coucou->win->mlx, coucou->win->win,
			item->texture->img->img_ptr, x, y);
}

void		ft_menu_inv(t_coucou *coucou)
{
	int		y;
	int		split;
	int		id;

	id = 0;
	split = coucou->win->width / 6;
	y = (coucou->win->height / 10) * 9;
	if (coucou->inventory)
	{
		if (coucou->inventory->actual_slot >= 1)
			ft_menu_inv2(coucou, coucou->inventory->slot1, split, y);
		if (coucou->inventory->actual_slot >= 2)
			ft_menu_inv2(coucou, coucou->inventory->slot1, 2 * split, y);
		if (coucou->inventory->actual_slot >= 3)
			ft_menu_inv2(coucou, coucou->inventory->slot1, 3 * split, y);
		if (coucou->inventory->actual_slot >= 4)
			ft_menu_inv2(coucou, coucou->inventory->slot1, 4 * split, y);
		if (coucou->inventory->actual_slot >= 5)
			ft_menu_inv2(coucou, coucou->inventory->slot1, 5 * split, y);
	}
}
