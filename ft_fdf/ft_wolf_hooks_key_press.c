/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_hooks_key_press.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:52:09 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 22:51:10 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_hooks_key_press_out_menu(t_coucou *coucou, int k)
{
	if (k == 126 || k == 13)
		coucou->p.move_up = 1;
	if (k == 125 || k == 1)
		coucou->p.move_down = 1;
	if (k == 124 || k == 2)
		coucou->p.move_left = 1;
	if (k == 123 || k == 0)
		coucou->p.move_right = 1;
	if (k == 49)
		coucou->p.move_speed = 0.2;
	if (k == 69 && coucou->p.can_open == 1)
		ft_wolf_destroy_block(coucou, 2, 2);
}

int		hooker(int k, t_coucou *coucou)
{
	if (k == 53)
		ft_wolf_hooks_exit(coucou);
	if (player_is_in_menu(coucou) == 0)
		ft_wolf_hooks_key_press_out_menu(coucou, k);
	else if (coucou->p.in_config == 1)
	{
		if (k == 126 || k == 13)
			coucou->texturepack -= (coucou->texturepack > 0) ? 1 : 0;
		if (k == 125 || k == 1)
		{
			if (coucou->texturepack + 1 < ft_files_count_dir_wa("./textures/"))
				coucou->texturepack++;
		}
		update_texture(coucou);
	}
	coucou->p.can_open = 0;
	hooker2(coucou);
	return (1);
}
