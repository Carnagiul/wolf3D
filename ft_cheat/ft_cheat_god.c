/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_god.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 09:31:59 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:33:01 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_god(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_god\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/god") != 0 || i != 1)
		ft_printf("Error: usage is /god\n");
	else
		coucou->p.is_god = (coucou->p.is_god == 0) ? 1 : 0;
	ft_strdel_array(split);
}
