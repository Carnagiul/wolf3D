/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:11:18 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:32:01 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_lstnew(void const *content, size_t len)
{
	t_list	*list;

	list = (t_list*)ft_malloc(sizeof(*list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_malloc(sizeof(content));
		if (list->content == NULL)
			return (NULL);
		ft_memcpy((list->content), content, len);
		list->content_size = len;
	}
	list->next = NULL;
	return (list);
}
