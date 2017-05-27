/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:23:27 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:27:48 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char				*ft_memchr(void const *src, int c, size_t len)
{
	unsigned char	*new;
	size_t			i;

	i = 0;
	new = (unsigned char *)src;
	while (len != 0)
	{
		if (new[i] == (unsigned char)c)
			return ((void *)src + i);
		i++;
		len--;
	}
	return (NULL);
}
