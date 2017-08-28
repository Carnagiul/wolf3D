/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_type_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:19:49 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:09:04 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_entity_type		*ft_entity_type_create(char *contentfile)
{
	char			**split;
	t_entity_type	*entity;
	int				i;

	i = 0;
	split = ft_strsplit(contentfile, '\t');
	entity = (t_entity_type *)ft_malloc(sizeof(t_entity_type));
	if (!split || !entity)
		exit(ft_printf("Error: Can't create t_entity_type *"));
	while (split[i])
		i++;
	if (i != 10)
		exit(ft_printf("Error: the entity_type file is corrupted...\n"));
	entity->type_id = ft_atoi(split[0]);
	entity->path = ft_strdup(split[1]);
	entity->name = ft_strdup(split[2]);
	entity->max_life = ft_atoi(split[3]);
	entity->damage_atk = ft_atoi(split[4]);
	entity->damage_cooldown = ft_atoi(split[5]);
	entity->damage_sound = ft_sound_create(split[7], split[6]);
	entity->death_sound = ft_sound_create(split[9], split[8]);
	entity->next = NULL;
	ft_strdel_array(split);
	return (entity);
}
