/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_texture_draw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 19:29:35 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/05 19:43:55 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_display_texture_stonebrick(int y, t_point pt,
		t_coucou *coucou, t_ray ray)
{
	t_point	pts[2];

	pts[0] = ft_create_point(pt.x, y);
	pts[1] = ft_create_point(pt.y, y);
	ft_wolf_display_texture(pts, ray, coucou->img, coucou->texture2);
}

void	ft_wolf_display_texture_woodenplanks(int y, t_point pt,
		t_coucou *coucou, t_ray ray)
{
	t_point	pts[2];

	pts[0] = ft_create_point(pt.x, y);
	pts[1] = ft_create_point(pt.y, y);
	ft_wolf_display_texture(pts, ray, coucou->img, coucou->texture3);
	if (ray.sidedist.x <= 2 && ray.sidedist.y <= 2)
		coucou->p.can_open = 1;
}
