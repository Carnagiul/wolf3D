/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:12:28 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:19:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void		ft_list_sort(t_list **begin_list)
{
	t_list	*temp;
	t_list	*temp2;
	void	*swap;
	size_t	size;

	temp = *begin_list;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (ft_strcmp(temp->content, temp2->content) > 0)
			{
				swap = temp->content;
				size = temp->content_size;
				temp->content = temp2->content;
				temp->content_size = temp2->content_size;
				temp2->content = swap;
				temp2->content_size = size;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
