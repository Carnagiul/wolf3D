/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_destroy_block.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 03:58:40 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 04:14:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_destroy_block(t_coucou *coucou, int id, int dist)
{
	int	x;
	int	y;

	x = (int)coucou->pos.x - dist;
	x = (x <= 0) ? 1 : x;
	while (x < ((int)coucou->pos.x + dist))
	{
		y = (int)coucou->pos.y - dist;
		if (x >= coucou->map.height - 1)
			return ;
		y = (y <= 0) ? 1 : y;
		while (y < ((int)coucou->pos.y + dist))
		{
			if (y >= coucou->map.width - 1)
				break ;
			if (coucou->map.world[x][y] == id || id == 0)
				coucou->map.world[x][y] = 0;
			y++;
		}
		x++;
	}
}
