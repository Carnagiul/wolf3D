/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:37:43 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:34:59 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	int l1;
	int l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	return (ft_memcmp((void const *)s1, (void const *)s2,
				(l1 >= l2) ? l1 : l2));
}
