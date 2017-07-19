/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_inventory_clear.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 04:54:09 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:22:27 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_wolf_clear_inventory(t_inventory *inv, t_win *win)
{
	if (inv)
	{
		if (inv->slot1)
			ft_wolf_item_clear(inv->slot1, win);
		if (inv->slot2)
			ft_wolf_item_clear(inv->slot2, win);
		if (inv->slot3)
			ft_wolf_item_clear(inv->slot3, win);
		if (inv->slot4)
			ft_wolf_item_clear(inv->slot4, win);
		if (inv->slot5)
			ft_wolf_item_clear(inv->slot5, win);
		inv->actual_slot = 0;
	}
}
