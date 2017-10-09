/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:14:32 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 17:30:32 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_list_push_param(int argc, char **argv)
{
	t_list	*list;
	t_list	*temp;
	int		i;

	if (argc < 1)
		return (0);
	i = 0;
	list = ft_lstnew(argv[i], (unsigned int)ft_strlen(argv[i]));
	i++;
	while (i < argc)
	{
		temp = list;
		list = ft_lstnew(argv[i], (unsigned int)ft_strlen(argv[i]));
		list->next = temp;
	}
	return (list);
}
