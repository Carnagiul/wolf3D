/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:55:04 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 06:56:17 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_entity			*ft_entity_create(int id, t_entity_type **type, t_vector pos)
{
	t_entity		*entity;
	t_entity_type	*etype;

	entity = (t_entity *)malloc(sizeof(t_entity));
	etype = *type;
	if (!entity || !etype)
		exit(ft_printf("Error: can't load t_entity * ft_entity_create\n"));
	entity->type_id = id;
	entity->pos = pos;
	entity->dir = create_vector(0, 0);
	entity->plan = create_vector(0, 0);
	entity->is_alive = 1;
	entity->last_atk = 0;
	entity->next = NULL;
	while (etype)
	{
		if (etype->type_id == id)
		{
			entity->health_actual = etype->max_life;
			return (entity);
		}
		etype = etype->next;
	}
	exit(ft_printf("Error: can't found entity ft_entity_create\n"));
	return (NULL);
}
