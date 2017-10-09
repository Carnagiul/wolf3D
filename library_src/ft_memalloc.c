/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:27:32 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:21:20 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = ft_malloc(size);
	if (!mem)
		exit(0);
	return ((mem == NULL) ? NULL : ft_memset(mem, 0, size));
}
