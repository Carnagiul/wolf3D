/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:12:45 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:19:22 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_front(t_list **list, void *data, size_t len)
{
	t_list	*temp;

	if (*list)
	{
		temp = ft_lstnew(data, len);
		temp->next = *list;
		*list = temp;
	}
	else
		*list = ft_lstnew(data, len);
}
