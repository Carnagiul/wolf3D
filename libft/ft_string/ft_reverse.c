/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:47:18 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:39:13 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	c;

	c = 0;
	i = 0;
	j = ft_strlen(str);
	while (i++ < j--)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
	return (str);
}
