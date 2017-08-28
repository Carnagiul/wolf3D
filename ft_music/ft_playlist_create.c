/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playlist_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 03:25:05 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:22:56 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_playlist		*ft_playlist_create(t_sound *sound)
{
	t_playlist	*list;

	list = (t_playlist *)ft_malloc(sizeof(t_playlist));
	if (!list || !sound)
	{
		ft_printf("Error: malloc playlist_create...\n");
		exit(1);
	}
	list->sound = sound;
	list->next = NULL;
	return (list);
}
