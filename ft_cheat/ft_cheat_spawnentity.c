/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_spawnentity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 07:33:08 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 07:39:32 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_spawnentity(t_coucou *coucou)
{
	char	**split;
	int		i;
	int		x;
	int		y;
	int		id;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_spawnentity\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/spawnentity") != 0 || i != 4)
		ft_printf("Error: usage is /spawnentity\n");
	else
	{
		x = ft_atoi(split[2]);
		y = ft_atoi(split[3]);
		id = ft_atoi(split[1]);
		if (coucou->map.world[x][y] == 0)
			ft_entity_add(&(coucou->entity), &(coucou->entity_type),
					create_vector(x, y), id);
		else
			ft_printf("Error: can't spawn entity at this point.\n");
	}
	ft_strdel_array(split);
}
