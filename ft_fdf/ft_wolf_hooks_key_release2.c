/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_hooks_key_release2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:41:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/23 22:42:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	hooker_cmp2(t_coucou *coucou)
{
	if (ft_strncmp(coucou->p.message, "/tp", 3) == 0)
		ft_cheat_tp(coucou);
	else if (ft_strncmp(coucou->p.message, "/give", 5) == 0)
		ft_cheat_give(coucou);
	else if (ft_strncmp(coucou->p.message, "/music", 6) == 0)
		ft_cheat_music(coucou);
	else if (ft_strncmp(coucou->p.message, "/damage", 7) == 0)
		ft_cheat_damage(coucou);
	else if (ft_strncmp(coucou->p.message, "/heal", 5) == 0)
		ft_cheat_heal(coucou);
	else if (ft_strncmp(coucou->p.message, "/rename", 7) == 0)
		ft_cheat_rename(coucou);
	else
		ft_printf("\033[1A\033[K%s say: @R%s@@\n\n",
				coucou->p.playername, coucou->p.message);
	free(coucou->p.message);
	coucou->p.message = ft_strdup("");
}
