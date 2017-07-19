/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat_damage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:11:44 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 09:37:52 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_damage(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	if (!split)
		exit(ft_printf("Error: malloc on ft_cheat_damage\n"));
	while (split[i])
		i++;
	if (ft_strcmp(split[0], "/damage") != 0 || i != 2)
		ft_printf("Error: usage is /damage\n");
	else if (coucou->p.is_god == 0)
		coucou->p.life -= ft_atoi(split[1]);
	else
		ft_printf("Error: the player is @MGOD@@\n\n");
	if (coucou->p.life < 0 || coucou->p.life > 100)
		coucou->p.life = 0;
	ft_strdel_array(split);
}
