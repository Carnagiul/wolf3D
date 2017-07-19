/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_stop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 09:44:15 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:49:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_stop(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_stop\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/stop") != 0 || i != 1)
		ft_printf("Error: usage is /stop\n");
	else
	{
		if (coucou->play_sound == 1)
			system("killall afplay");
		coucou->play_sound = 0;
	}
	ft_strdel_array(split);
}
