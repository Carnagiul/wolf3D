/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_hooks_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:55:28 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/19 06:37:35 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wolf_hooks_exit(t_coucou *coucou)
{
	(void)coucou;
	system("killall afplay");
	if (coucou->p.life <= 0)
		ft_printf("Vous etes morts... Merci d'avoir jouer a @GWolfd3D@@\n");
	exit(0);
}
