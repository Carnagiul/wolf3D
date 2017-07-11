/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_item_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 04:47:03 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/11 05:15:25 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		print_item(t_item *item)
{
	ft_printf("\n\n");
	ft_printf("item_id %d\n", item->id);
	ft_printf("item_type_id %d\n", item->type_id);
	ft_printf("item_amount_ammo %d\n", item->amount_ammo);
	ft_printf("item_max_ammo %d\n", item->max_ammo);
	ft_printf("item_amount_size %d\n", item->size_actual);
	ft_printf("item_max_stack_size %d\n", item->max_stack_size);
	ft_printf("item_sound_get_time %d\n", item->get_sound->len);
	ft_printf("item_sound_get_name %s\n", item->get_sound->sound);
	ft_printf("item_sound_drop_time %d\n", item->drop_sound->len);
	ft_printf("item_sound_drop_name %s\n", item->drop_sound->sound);
	ft_printf("item_sound_use_time %d\n", item->use_sound->len);
	ft_printf("item_sound_use_name %s\n", item->use_sound->sound);
	ft_printf("item_name %s\n", item->name);
	ft_printf("\n\n");
}

void		print_list_items(t_item **item_list, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_printf("\n\n@Rnew item found@@\n\n");
		ft_printf("item_id [@G%d@@]\n", item_list[i]->id);
		i++;
	}
}
