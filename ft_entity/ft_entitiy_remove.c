/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 06:16:49 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 06:50:22 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
			{
				tmp->next = ent->next;
				free(tmp);
				tmp = ent;
				return ;
			}
		}
		if (tmp->id == id)
		{
			tmp2->next = NULL;
			free(tmp);
		}
	}
}
