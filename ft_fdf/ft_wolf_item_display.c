/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_item_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 04:47:03 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/10 05:23:02 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		print_list_item(t_item **item_list, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_printf("\n\n@Rnew item found@@\n\n");
		ft_printf("item_id [@G%d@@]\n", item_list[i]->id);
		if (item_list[i]->type_id == 1)
			ft_printf("item_type @Gblocks@@\n")
		if (item_list[i]->type_id == 1)
			ft_printf("item_type @Gblocks@@\n")
	}
}
