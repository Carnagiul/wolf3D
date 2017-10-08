/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_calc_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:02:16 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/08 18:52:10 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_hooks_move_up(t_coucou *coucou)
{
	double	x;
	double	y;

	x = coucou->pos.x + coucou->dir.x * coucou->p.move_speed;
	y = coucou->pos.y + coucou->dir.y * coucou->p.move_speed;
	if (x < 0 || x >= coucou->map.height)
		x = (x < 0) ? 0 : coucou->map.height - 1;
	if (y < 0 || y >= coucou->map.width)
		y = (y < 0) ? 0 : coucou->map.width - 1;
	if (!coucou->map.world[(int)x][(int)coucou->pos.y])
		coucou->pos.x = x;
	if (!coucou->map.world[(int)coucou->pos.x][(int)y])
		coucou->pos.y = y;
}

void	ft_wolf_hooks_move_down(t_coucou *coucou)
{
	double	x;
	double	y;

	x = coucou->pos.x - coucou->dir.x * coucou->p.move_speed;
	y = coucou->pos.y - coucou->dir.y * coucou->p.move_speed;
	if (x < 0 || x >= coucou->map.height)
		x = (x < 0) ? 0 : coucou->map.height - 1;
	if (y < 0 || y >= coucou->map.width)
		y = (y < 0) ? 0 : coucou->map.width - 1;
	if (!coucou->map.world[(int)x][(int)coucou->pos.y])
		coucou->pos.x = x;
	if (!coucou->map.world[(int)coucou->pos.x][(int)y])
		coucou->pos.y = y;
}

void	ft_wolf_hooks_move_right(t_coucou *coucou)
{
	double olddirx;
	double oldplanex;

	olddirx = coucou->dir.x;
	coucou->dir.x = coucou->dir.x * cos(coucou->p.rotate_speed) -
		coucou->dir.y * sin(coucou->p.rotate_speed);
	coucou->dir.y = olddirx * sin(coucou->p.rotate_speed) +
		coucou->dir.y * cos(coucou->p.rotate_speed);
	oldplanex = coucou->plan.x;
	coucou->plan.x = coucou->plan.x * cos(coucou->p.rotate_speed) -
		coucou->plan.y * sin(coucou->p.rotate_speed);
	coucou->plan.y = oldplanex * sin(coucou->p.rotate_speed) +
		coucou->plan.y * cos(coucou->p.rotate_speed);
}

void	ft_wolf_hooks_move_left(t_coucou *coucou)
{
	double olddirx;
	double oldplanex;

	olddirx = coucou->dir.x;
	coucou->dir.x = coucou->dir.x * cos(-coucou->p.rotate_speed) -
		coucou->dir.y * sin(-coucou->p.rotate_speed);
	coucou->dir.y = olddirx * sin(-coucou->p.rotate_speed) +
		coucou->dir.y * cos(-coucou->p.rotate_speed);
	oldplanex = coucou->plan.x;
	coucou->plan.x = coucou->plan.x * cos(-coucou->p.rotate_speed) -
		coucou->plan.y * sin(-coucou->p.rotate_speed);
	coucou->plan.y = oldplanex * sin(-coucou->p.rotate_speed) +
		coucou->plan.y * cos(-coucou->p.rotate_speed);
}
