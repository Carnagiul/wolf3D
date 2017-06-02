/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 23:20:16 by piquerue          #+#    #+#             */
/*   Updated: 2017/06/02 03:28:38 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int					get_fps(void)
{
	static struct timeval		prev;
	static struct timeval		t;
	unsigned int				fps;

	gettimeofday(&t, NULL);
	fps = ((t.tv_sec * 1000000 + t.tv_usec) - (prev.tv_sec * 1000000 +
				prev.tv_usec));
	prev = t;
	return (1000000 / fps);
}
