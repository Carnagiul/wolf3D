/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_type_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:44:13 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 06:50:31 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_entity_type_add(t_entity_type **type, char *filecontent)
{
	t_entity_type *entity;

	entity = *type;
	if (entity)
	{
		while (entity->next)
			entity = entity->next;
		entity->next = ft_entity_type_create(filecontent);
	}
	else
		*type = ft_entity_type_create(filecontent);
}
