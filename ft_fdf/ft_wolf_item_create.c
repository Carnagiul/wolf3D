/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_item_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 02:20:24 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 03:21:42 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		get_item_id2(char **split, t_win *win, t_item *item)
{
	item->id = ft_atoi(split[0]);
	item->type_id = ft_atoi(split[1]);
	item->amount_ammo = ft_atoi(split[2]);
	item->max_ammo = ft_atoi(split[3]);
	item->name = ft_strdup(split[4]);
	item->texture_name = ft_strdup(split[5]);
	item->texture = ft_mlx_load_texture(split[5], win);
	item->size_actual = ft_atoi(split[6]);
	item->max_stack_size = ft_atoi(split[7]);
	item->get_sound = ft_sound_create(split[9], split[8]);
	item->drop_sound = ft_sound_create(split[11], split[10]);
	item->use_sound = ft_sound_create(split[13], split[12]);
}

t_item		*get_item_id(int id, char *data_line, t_win *win)
{
	t_item	*item;
	char	**split;

	item = (t_item *)malloc(sizeof(t_item));
	split = ft_strsplit(data_line, '\t');
	if (!item || is_valid_item(split) != 0)
	{
		ft_printf("Error: ./ressources/list_item.wolf3d was wrong indent.\n");
		exit(0);
	}
	get_item_id2(split, win, item);
	ft_strdel_array(split);
	(void)id;
	return (item);
}
