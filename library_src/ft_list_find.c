/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:09:45 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:29:48 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_list_find(t_list *begin_list, void *data)
{
	t_list	*list;

	list = begin_list;
	while (list)
	{
		if (ft_strcmp(data, list->content) == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
