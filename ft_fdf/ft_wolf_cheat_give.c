/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_cheat_give.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 03:48:03 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/11 07:28:31 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_inventory		*ft_wolf_inventory_init(void)
{
	t_inventory	*inv;

	inv = (t_inventory *)malloc(sizeof(t_inventory));
	if (!inv)
	{
		ft_printf("Error: can't create inventory...\n");
		exit(0);
	}
	inv->actual_slot = 0;
	return (inv);
}

void		free_t_sound(t_sound *sound)
{
	free(sound->sound);
	free(sound);
}

void		ft_wolf_item_clear(t_item *item, t_win *win)
{
	if (item)
	{
		free(item->name);
		free(item->texture_name);
		free(item->texture->name);
		free_t_img(item->texture->img, win);
		free(item->texture);
		free_t_sound(item->get_sound);
		free_t_sound(item->drop_sound);
		free_t_sound(item->use_sound);
		free(item);
	}
}

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
	ft_printf("euuuu nop\n");
}

t_sound		*ft_wolf_sound_copy_content(t_sound *src)
{
	t_sound	*sound;

	sound = (t_sound *)malloc(sizeof(t_sound));
	if (!sound)
	{
		ft_printf("Error: can't copy content of sound...\n");
		exit(0);
	}
	sound->len = src->len;
	sound->sound = ft_strdup(src->sound);
	return (sound);
}

t_item		*ft_wolf_item_copy_content(t_item *src)
{
	t_item	*item;

	item = (t_item *)malloc(sizeof(t_item));
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
	return (item);
}

void		ft_wolf_inventory_set_item(t_inventory *inv, t_item *item)
{
	if (inv->actual_slot == 4)
	{
		inv->slot5 = ft_wolf_item_copy_content(item);
		inv->actual_slot = 5;
	}
	if (inv->actual_slot == 3)
	{
		inv->slot4 = ft_wolf_item_copy_content(item);
		inv->actual_slot = 4;
	}
	if (inv->actual_slot == 2)
	{
		inv->slot3 = ft_wolf_item_copy_content(item);
		inv->actual_slot = 3;
	}
	if (inv->actual_slot == 1)
	{
		inv->slot2 = ft_wolf_item_copy_content(item);
		inv->actual_slot = 2;
	}
	if (inv->actual_slot == 0)
	{
		inv->slot1 = ft_wolf_item_copy_content(item);
		inv->actual_slot = 1;
	}
	return ;
}

void		ft_wolf_give(t_coucou *coucou, int id)
{
	int		i;

	i = 0;
	while (coucou->list_items[i] != NULL)
	{
		if (coucou->list_items[i]->id == id)
		{
			if (!coucou->inventory)
				coucou->inventory = ft_wolf_inventory_init();
			if (coucou->inventory->actual_slot == 5)
				ft_wolf_clear_inventory(coucou->inventory, coucou->win);
			ft_wolf_inventory_set_item(coucou->inventory, coucou->list_items[i]);
			return ;
		}
		i++;
	}
}
