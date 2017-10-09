/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entitiy_type_load.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 06:42:44 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 06:46:03 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_entity_type_load(t_entity_type **type, t_win *win)
{
	t_entity_type *ents;

	ents = *type;
	if (!ents)
		exit(ft_printf("Error: Can't load img ft_entity_type_load...\n"));
	while (ents->next)
	{
		ents->img = ft_mlx_extended_gen_imgxpm(win, ents->path);
		ents = ents->next;
	}
	ents->img = ft_mlx_extended_gen_imgxpm(win, ents->path);
}
