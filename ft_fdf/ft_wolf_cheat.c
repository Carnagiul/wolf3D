/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_cheat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 04:08:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 09:21:59 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_cheat_destroy(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_strsplit(coucou->p.message, ' ');
	if (ft_strcmp(split[0], "/destroy") != 0)
	{
		ft_printf("Error: command is /destroy <blockid> <range>");
		return ;
	}
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

/*
**		ft_wolf_give(coucou, ft_atoi(split[1]));
**		print_item(coucou->inventory->slot1);
*/

void		ft_cheat_give(t_coucou *coucou)
{
	char	**split;
	int		i;

	ft_printf("@RDATA@@\n\n");
	split = ft_strsplit(coucou->p.message, ' ');
	i = 1;
	if (ft_strcmp(split[0], "/give") != 0)
	{
		ft_printf("Error: command is /give <item_id>");
		return ;
	}
	while (split[i])
		i++;
	if (i == 2)
	{
		ft_printf("@RDATA@@\n");
		ft_wolf_give(coucou, ft_atoi(split[1]));
	}
	else
		ft_printf("Error: command is /give <item_id>");
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void		ft_cheat_tp(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_strsplit(coucou->p.message, ' ');
	if (ft_strcmp(split[0], "/tp") != 0)
	{
		ft_printf("Error: command is /tp <x> <y>");
		return ;
	}
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

void		ft_cheat_music(t_coucou *coucou)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(coucou->p.message, ' ');
	while (split[i])
		i++;
	if (i != 2)
	{
		ft_printf("Error: command is /music next");
		return ;
	}
	if (ft_strcmp(split[1], "next") != 0 || ft_strcmp(split[0], "/music") != 0)
	{
		ft_printf("Error: command is /music next");
		return ;
	}
	coucou->playlist = coucou->playlist->next;
	ft_playlist_forceplay(&coucou->playlist);
	ft_strdel_array(split);
}
