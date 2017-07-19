/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_heal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:10:18 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:37:18 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_heal(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_heal\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/heal") != 0 || i != 1)
		ft_printf("Error: usage is /heal\n");
	else
		coucou->p.life = 100;
	ft_strdel_array(split);
}
