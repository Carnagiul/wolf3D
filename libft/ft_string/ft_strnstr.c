/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:22:59 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:36:55 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	i = 0;
	if (to_find == NULL && str == NULL)
		return (0);
	if (ft_strequ(str, to_find) == 1 && ft_strcmp(str, "") == 0)
		return ((char *)str);
	j = ft_strlen(to_find);
	while (str[i] != '\0' && len > i)
	{
		k = 0;
		while (str[i + k] == to_find[k] && str[i + k] != '\0' && str[i] != '\0')
			k++;
		if (k == j && (i + k) <= len)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
