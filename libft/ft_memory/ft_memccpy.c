/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:02:37 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:27:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str_dest;
	unsigned char	*str_src;

	i = 0;
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		if ((unsigned char)c == str_dest[i])
			return ((void *)&str_dest[i + 1]);
		i++;
	}
	return (NULL);
}
