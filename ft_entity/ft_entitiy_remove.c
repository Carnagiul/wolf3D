/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 06:16:49 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/23 18:12:13 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_entity_del(t_entity *tmp, t_entity *ent)
{
	tmp->next = ent->next;
	free(tmp);
	tmp = ent;
	return ;
}

void			ft_entity_remove(t_entity **ents, int id)
{
	t_entity	*ent;
	t_entity	*tmp;
	t_entity	*tmp2;

	ent = *ents;
	tmp = NULL;
	if (ent)
	{
		while (ent->next)
		{
			tmp2 = tmp;
			tmp = ent;
			ent = ent->next;
			if (tmp->id == id)
				return (ft_entity_del(tmp, ent));
		}
		if (tmp->id == id)
		{
			tmp2->next = NULL;
			free(tmp);
		}
	}
}
