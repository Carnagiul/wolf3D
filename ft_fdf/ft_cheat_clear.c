/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:56:53 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 21:30:03 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_clear(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_clear\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/clear") != 0 || i != 1)
		ft_printf("Error: usage is /clear\n");
	else
		ft_wolf_clear_inventory(coucou->inventory, coucou->win);
	ft_strdel_array(split);
}
