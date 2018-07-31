/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:33:04 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:36:41 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, char const *src, size_t n)
{
	unsigned int	i;

	i = 0;
	ft_memset(dest, 0, n);
	while (0 < n && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (dest);
}
