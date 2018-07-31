/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:14:00 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:19:24 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*temp;
	t_list	*temp2;

	list = *begin_list;
	if (!list || !(list->next))
		return ;
	temp = list->next;
	temp2 = temp->next;
	while (temp2)
	{
		list = temp;
		temp = temp2;
		temp2 = temp2->next;
		temp->next = list;
	}
	*begin_list = temp;
}
