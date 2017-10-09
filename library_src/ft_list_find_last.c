/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:09:18 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:29:55 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_list_find_last(t_list *list)
{
	t_list	*temp;

	if (!list)
		return (NULL);
	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
