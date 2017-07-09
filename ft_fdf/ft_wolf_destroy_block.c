/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_destroy_block.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 03:58:40 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/08 00:54:41 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		check_arround(t_coucou *coucou, int i, int col)
{
	char	**split;
	int		k;
	int		cp;

	i = (i < 0) ? 0 : i;
	split = ft_strsplit(coucou->map.map[i], ' ');
	k = 0;
	cp = 0;
	while (split[k])
		k++;
	k--;
	cp = (k > col) ? 0 : 1;
	while (k >= 0)
		free(split[k--]);
	free(split);
	if (cp == 1 || col <= 0)
		return (1);
	return (0);
}

int		block_exist(t_coucou *coucou, int i, int col)
{
	char	**split;
	int		k;
	int		cp;

	split = ft_strsplit(coucou->map.map[i], ' ');
	k = 0;
	cp = 0;
	while (split[k])
		k++;
	k--;
	cp = (k > col) ? 0 : 1;
	while (k >= 0)
		free(split[k--]);
	free(split);
	if (cp == 1 || col <= 0 || check_arround(coucou, i - 1, col))
		return (1);
	return (0);
}

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
			if (block_exist(coucou, x, y) == 0)
			{
				if (coucou->map.world[x][y] == id || id == 0)
					coucou->map.world[x][y] = 0;
			}
			y++;
		}
		x++;
	}
}
