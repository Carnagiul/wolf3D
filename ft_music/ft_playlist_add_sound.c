/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playlist_add_sound.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 03:31:38 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 07:08:39 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_playlist_add_sound(t_playlist **playlist, t_sound *sound)
{
	t_playlist	*list;

	ft_printf("new music detected %s ==> %d\n", sound->sound, sound->len);
	list = *playlist;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_playlist_create(sound);
		ft_printf("pushback playlist\n");
	}
	else
	{
		ft_printf("creation playlist\n");
		*playlist = ft_playlist_create(sound);
	}
}
