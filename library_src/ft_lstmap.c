/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:11:12 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:31:52 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (list)
	{
		new = f(list);
		if (list->next)
			new->next = ft_lstmap(list->next, f);
	}
	return (new);
}
