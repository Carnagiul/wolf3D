/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_rename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:05:49 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 08:35:50 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_rename(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_rename\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/rename") != 0 || i != 2)
		ft_printf("Error: usage is /rename\n");
	else
	{
		ft_strdel(&(coucou->p.playername));
		coucou->p.playername = ft_strdup(split[1]);
	}
	ft_strdel_array(split);
}
