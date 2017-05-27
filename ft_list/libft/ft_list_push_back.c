/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:09:26 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:19:21 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void		ft_list_push_back(t_list **list, void *data, size_t len)
{
	t_list	*temp;

	temp = *list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(data, len);
	}
	else
		*list = ft_lstnew(data, len);
}
