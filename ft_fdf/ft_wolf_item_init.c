/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_item_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 00:29:57 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/11 04:34:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_item		**get_list_item(t_win *win)
{
	char	*file_content;
	char	**split_file_content;
	int		count;
	t_item	**item_list;

	file_content = ft_get_content_file("./ressources/item_list.wolf3d");
	split_file_content = ft_strsplit(file_content, '\n');
	count = count_item_list(split_file_content);
	item_list = (t_item **)malloc(sizeof(t_item *) * count);
	if (count == 0 || !item_list)
	{
		ft_printf("Error: can't create items list...\n");
		exit(0);
	}
	load_itemlist(split_file_content, item_list, win);
	ft_strdel_array(split_file_content);
	free(file_content);
	return (item_list);
}
