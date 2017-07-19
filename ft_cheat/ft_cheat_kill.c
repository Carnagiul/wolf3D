/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 03:42:39 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 03:44:09 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_kill(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_damage\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/kill") != 0 || i != 1)
		ft_printf("Error: usage is /kill\n");
	else
		coucou->p.life = 0;;
	ft_strdel_array(split);
}
