/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:26:27 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:27:52 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	unsigned int	i;

	i = 0;
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	if (str_dest > str_src)
	{
		while (i < len)
		{
			str_dest[len - 1] = str_src[len - 1];
			len--;
		}
		return (dest);
	}
	else
		while (i < len)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	return (dest);
}
