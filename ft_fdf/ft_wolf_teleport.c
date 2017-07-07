/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_teleport.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 04:03:28 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 04:11:56 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_tp(t_coucou *coucou, int x, int y)
{
	if (x <= 0)
		return ;
	if (y <= 0)
		return ;
	if (x >= coucou->map.height - 1)
		return ;
	if (y >= coucou->map.width - 1)
		return ;
	if (coucou->map.world[x][y] == 0)
	{
		coucou->pos.x = (double)x;
		coucou->pos.x = (double)y;
	}
	else
		return ;
}
