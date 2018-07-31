/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:57:42 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:29:25 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, void const *src, size_t size)
{
	char	*ptdest;
	char	*ptsrc;

	ptdest = (char *)dest;
	ptsrc = (char *)src;
	while (size-- > 0)
		*ptdest++ = *ptsrc++;
	return (dest);
}
