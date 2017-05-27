/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:10:54 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:19:44 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void		ft_lstdel(t_list **list, void (*del)(void *, size_t))
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		ft_lstdelone(list, del);
		*list = temp;
	}
}
