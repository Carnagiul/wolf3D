/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:09:12 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:18:34 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list		*ft_list_at(t_list *list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (!list)
		return (NULL);
	while (i++ <= nbr)
		list = list->next;
	if (i > nbr)
		return (list);
	return (0);
}
