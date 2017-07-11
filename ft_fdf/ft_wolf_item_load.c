/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_item_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 00:22:52 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/11 07:28:12 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		load_itemlist(char **split, t_item **items, t_win *win)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (split[i])
	{
		if (split[i][0] != '#')
		{
			items[k] = get_item_id(k, split[i], win);
			k++;
		}
		i++;
	}
}
