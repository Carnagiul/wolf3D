/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playlist_boucle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 03:28:40 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 07:08:48 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_playlist_boucle(t_playlist **playlist)
{
	t_playlist	*list;
	t_playlist	*first;

	list = *playlist;
	first = *playlist;
	if (!list)
	{
		ft_printf("Error: can't boucle the playlist...\n");
		exit(0);
	}
	while (list->next)
		list = list->next;
	list->next = first;
	ft_playlist_forceplay(&first);
}
