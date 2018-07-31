/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:24:18 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:36:37 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t i;
	size_t c;
	size_t result;

	i = 0;
	c = 0;
	result = (size_t)(ft_strlen(dest) + ft_strlen(src));
	while (dest[i] != 0 && i < size)
		i++;
	if ((size - i) == 0)
		return (i + ft_strlen(src));
	while (i != (size - 1) && src[c] != 0)
		dest[i++] = src[c++];
	dest[i] = 0;
	return (result);
}
