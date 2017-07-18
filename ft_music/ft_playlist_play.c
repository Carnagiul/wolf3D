/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playlist_play.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 05:17:48 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 07:21:13 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				skip_music(t_playlist *play)
{
	if (clock() - play->start >= play->end - play->start)
		return (1);
	return (0);
}

void			ft_playlist_forceplay(t_playlist **play)
{
	char		*syscall;

	(*play)->start = clock();
	(*play)->end = clock() + (1000000 * (*play)->sound->len);
	system("killall afplay");
	syscall = ft_strdup("afplay ./ressources/music/");
	syscall = ft_free_join1(syscall, (*play)->sound->sound);
	syscall = ft_free_join1(syscall, " &");
	system(syscall);
	ft_printf("Lancement de la music @G%s@@\n\n", syscall);
	ft_strdel(&syscall);
}

t_playlist		*ft_playlist_play(t_playlist *play)
{
	if (skip_music(play))
	{
		play = play->next;
		ft_playlist_forceplay(&play);
	}
	return (play);
}
