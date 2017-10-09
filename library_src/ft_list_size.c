/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:12:36 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:30:49 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_list_size(t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (list)
	{
		temp = list;
		while (temp)
		{
			i++;
			temp = temp->next;
		}
	}
	return (i);
}
