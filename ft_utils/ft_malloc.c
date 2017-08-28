/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 02:04:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:10:33 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_malloc(size_t size)
{
	void	*data;

	data = malloc(size);
	if (!data)
	{
		ft_putstr("Error on malloc\n");
		exit(0);
	}
	return (data);
}
