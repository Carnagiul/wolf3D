/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_hooks_key_release.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:30:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 04:11:40 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_fdf_map.h"

void	hooker_not_in_menu(t_coucou *coucou, int k)
{
	if (k == 126 || k == 13)
		coucou->p.move_up = 0;
	if (k == 125 || k == 1)
		coucou->p.move_down = 0;
	if (k == 124 || k == 2)
		coucou->p.move_left = 0;
	if (k == 123 || k == 0)
		coucou->p.move_right = 0;
	if (k == 49)
		coucou->p.move_speed = 0.1;
}

int		player_is_in_menu(t_coucou *coucou)
{
	if (coucou->p.in_menu_map == 1)
		return (1);
	if (coucou->p.in_config == 1)
		return (1);
	if (coucou->p.in_chat == 1)
		return (1);
	return (0);
}

int		check_if_char_is_auth(int k, t_coucou *coucou)
{
	int	i;

	i = 0;
	while (i < 38)
	{
		if (k == g_t_keycode[i].keycode)
		{
			coucou->p.message = ft_free_join1(coucou->p.message,
					g_t_keycode[i].key);
			return (1);
		}
		i++;
	}
	return (0);
}

int		hooker_release(int k, t_coucou *coucou)
{
	int	j;

	if (player_is_in_menu(coucou) == 0)
		hooker_not_in_menu(coucou, k);
	if (coucou->p.in_chat == 1)
	{
		j = check_if_char_is_auth(k, coucou);
		if (k == 76 && j == 0)
		{
			if (ft_strncmp(coucou->p.message, "/destroy", 8) == 0)
				ft_cheat_destroy(coucou);
			if (ft_strncmp(coucou->p.message, "/tp", 3) == 0)
				ft_cheat_tp(coucou);
			else
				ft_printf("\033[1A\033[K%s say: @R%s@@\n\n", "George",
					coucou->p.message);
			free(coucou->p.message);
			coucou->p.message = ft_strdup("");
		}
	}
	hooker2(coucou);
	return (1);
}
