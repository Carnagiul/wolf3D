/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:54:44 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/18 07:13:55 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int	main(int argc, char **argv)
int	main(void)
{
	t_playlist	*play;

	play = ft_playlist_load();
	while (1)
		play = ft_playlist_play(play);
	//ft_wolf_init(argc, argv);
	return (0);
}
