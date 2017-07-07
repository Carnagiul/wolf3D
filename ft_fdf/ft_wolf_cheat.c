/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_cheat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 04:08:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/07 04:56:40 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_cheat_destroy(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_strsplit(coucou->p.message, ' ');
	while (split[i])
		i++;
	if (i == 3)
		ft_wolf_destroy_block(coucou, ft_atoi(split[1]), ft_atoi(split[2]));
	else
		ft_printf("Error: command is /destroy <blockid> <range>\n\n");
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_cheat_tp(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_strsplit(coucou->p.message, ' ');
	while (split[i])
		i++;
	if (i == 3)
		ft_wolf_tp(coucou, ft_atoi(split[1]), ft_atoi(split[2]));
	else
		ft_printf("Error: command is /tp <x> <y>\n\n");
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
