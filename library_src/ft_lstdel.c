/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:10:54 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:31:16 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
