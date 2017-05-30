/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_chat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 05:04:21 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/30 06:10:05 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_menu_chat(t_coucou *coucou)
{
	mlx_string_put(coucou->win->mlx, coucou->win->win, 100, 100, 0xFFFFFF, coucou->p.message);
}
