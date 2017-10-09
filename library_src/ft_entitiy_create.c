/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:55:04 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:08:16 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_entity			*ft_entity_init(int id, t_vector pos)
{
	t_entity		*e;

	e = (t_entity *)ft_malloc(sizeof(t_entity));
	if (!e)
		exit(ft_printf("Error: can't load t_entity * ft_entity_create\n"));
	e->type_id = id;
	e->pos = pos;
	e->dir = create_vector(0, 0);
	e->plan = create_vector(0, 0);
	e->is_alive = 1;
	e->last_atk = 0;
	e->next = NULL;
	return (e);
}

t_entity			*ft_entity_create(int id, t_entity_type **type,
		t_vector pos)
{
	t_entity		*entity;
	t_entity_type	*etype;

	etype = *type;
	entity = ft_entity_init(id, pos);
	if (!entity || !etype)
		exit(ft_printf("Error: can't load t_entity * ft_entity_create\n"));
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
