/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 06:08:01 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 06:50:03 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_entity_add(t_entity **ents, t_entity_type **type, t_vector pos, int type_id)
{
	t_entity	*ent;

	ent = *ents;
	if (ent)
	{
		while (ent->next)
			ent = ent->next;
		ent->next = ft_entity_create(type_id, type, pos);
		ent->next->id = ent->id + 1;
	}
	else
	{
		*ents = ft_entity_create(type_id, type, pos);
		(*ents)->id = 1;
	}
}
