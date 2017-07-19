/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_hooks_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:16:40 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 08:55:27 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	click_on_map(int x, int y, t_coucou *coucou)
{
	if (x >= (coucou->win->width - coucou->xmap->width) && y >=
			(coucou->win->height - coucou->xmap->height))
	{
		coucou->p.in_menu_map = (coucou->p.in_menu_map == 0) ? 1 : 0;
		coucou->p.in_config = 0;
		coucou->p.in_chat = 0;
		coucou->p.in_inventory = 0;
	}
}

void	click_on_chat(int x, int y, t_coucou *coucou)
{
	if (x <= (coucou->win->width - coucou->chat->width) && y <=
			(coucou->chat->height))
	{
		coucou->p.in_chat = (coucou->p.in_chat == 0) ? 1 : 0;
		coucou->p.in_config = 0;
		coucou->p.in_menu_map = 0;
		coucou->p.in_inventory = 0;
	}
}

void	click_on_cfg(int x, int y, t_coucou *coucou)
{
	if (x >= (coucou->win->width - coucou->settings->width) && y <=
			(coucou->win->height - coucou->settings->height))
	{
		coucou->p.in_config = (coucou->p.in_config == 0) ? 1 : 0;
		coucou->p.in_chat = 0;
		coucou->p.in_menu_map = 0;
		coucou->p.in_inventory = 0;
	}
}

int		mouse_click(int keycode, int x, int y, t_coucou *coucou)
{
	if (keycode == 1)
	{
		click_on_map(x, y, coucou);
		click_on_cfg(x, y, coucou);
		click_on_chat(x, y, coucou);
		if (player_is_in_menu(coucou) == 0)
			ft_wolf_item_usage(coucou);
	}
	if (keycode == 3)
	{
		ft_printf("molette descendante donc on passe a itemid - 1\n\n");
	}
	if (keycode == 4)
	{
		ft_printf("molette ascendante donc on passe a itemid + 1\n\n");
	}
	hooker2(coucou);
	return (1);
}
