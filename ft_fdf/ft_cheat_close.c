/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:03:25 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 06:42:18 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_close(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_exit\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/close") != 0 || i != 1)
		ft_printf("Error: usage is /close\n");
	else
		ft_wolf_hooks_exit(coucou);
	ft_strdel_array(split);
}
