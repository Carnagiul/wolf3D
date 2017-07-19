/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_item_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:34:43 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:23:12 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_wolf_item_clear(t_item *item, t_win *win)
{
	if (item)
	{
		free(item->name);
		free_t_sound(item->get_sound);
		free_t_sound(item->drop_sound);
		free_t_sound(item->use_sound);
		free(item);
		item = NULL;
	}
	(void)win;
}
