/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_play.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 09:44:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:49:46 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_play(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_play\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/play") != 0 || i != 1)
		ft_printf("Error: usage is /play\n");
	else
	{
		if (coucou->play_sound == 0)
		{
			coucou->playlist = coucou->playlist->next;
			ft_playlist_forceplay(&coucou->playlist);
		}
		coucou->play_sound = 1;
	}
	ft_strdel_array(split);
}
