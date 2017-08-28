/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_cheat_give.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:03 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:12:14 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_sound		*ft_wolf_sound_copy_content(t_sound *src)
{
	t_sound	*sound;

	sound = (t_sound *)ft_malloc(sizeof(t_sound));
	if (!sound)
	{
		ft_printf("Error: can't copy content of sound...\n");
		exit(0);
	}
	sound->len = src->len;
	sound->sound = ft_strdup(src->sound);
	return (sound);
}

t_item		*ft_wolf_item_copy_content(t_item *src, t_win *win)
{
	t_item	*item;

	item = (t_item *)ft_malloc(sizeof(t_item));
	if (!item)
	{
		ft_printf("Error: can't copy item...\n");
		exit(0);
	}
	item->id = src->id;
	item->type_id = src->type_id;
	item->amount_ammo = src->amount_ammo;
	item->max_ammo = src->max_ammo;
	item->size_actual = src->size_actual;
	item->max_stack_size = src->max_stack_size;
	item->name = ft_strdup(src->name);
	item->get_sound = ft_wolf_sound_copy_content(src->get_sound);
	item->drop_sound = ft_wolf_sound_copy_content(src->drop_sound);
	item->use_sound = ft_wolf_sound_copy_content(src->use_sound);
	item->texture = src->texture;
	(void)win;
	return (item);
}

void		ft_wolf_inventory_set_item(t_inventory *inv, t_item *item,
		t_win *win)
{
	if (inv->actual_slot == 4)
	{
		inv->slot5 = ft_wolf_item_copy_content(item, win);
		inv->actual_slot = 5;
	}
	if (inv->actual_slot == 3)
	{
		inv->slot4 = ft_wolf_item_copy_content(item, win);
		inv->actual_slot = 4;
	}
	if (inv->actual_slot == 2)
	{
		inv->slot3 = ft_wolf_item_copy_content(item, win);
		inv->actual_slot = 3;
	}
	if (inv->actual_slot == 1)
	{
		inv->slot2 = ft_wolf_item_copy_content(item, win);
		inv->actual_slot = 2;
	}
	if (inv->actual_slot == 0)
	{
		inv->slot1 = ft_wolf_item_copy_content(item, win);
		inv->actual_slot = 1;
	}
}

void		ft_wolf_give(t_coucou *coucou, int id)
{
	int		i;

	i = 0;
	while (i < coucou->list_items[0]->max_item_array)
	{
		if (coucou->list_items[i]->id == id)
		{
			if (!coucou->inventory)
				coucou->inventory = ft_wolf_inventory_init();
			if (coucou->inventory->actual_slot == 5)
			{
				ft_printf("@RError@@: You're inventory is @Bfull@@...\n\n");
				return ;
			}
			ft_wolf_inventory_set_item(coucou->inventory,
					coucou->list_items[i], coucou->win);
		}
		i++;
	}
}
