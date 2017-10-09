/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playlist_add_sound.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 03:31:38 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/20 05:54:51 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_playlist_add_sound(t_playlist **playlist, t_sound *sound)
{
	t_playlist	*list;

	list = *playlist;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_playlist_create(sound);
	}
	else
		*playlist = ft_playlist_create(sound);
}
