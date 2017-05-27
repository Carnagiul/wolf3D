/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 03:16:53 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/16 23:58:59 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_MAP_H
# define FT_FDF_MAP_H

t_fdf_map	g_t_fdf_map[] = {
	{67, L"*", &ft_fractol_zoom_in_key},
	{75, L"/", &ft_fractol_zoom_out_key},
	{69, L"+", &ft_fractol_increment_iteration},
	{78, L"-", &ft_fractol_decrement_iteration},
	{15, L"r", &ft_fractol_reset},
	{53, L"esc", &ft_fractol_esc},
	{123, L"←", &ft_fractol_key_left},
	{124, L"→", &ft_fractol_key_right},
	{125, L"↓", &ft_fractol_key_down},
	{126, L"↑", &ft_fractol_key_up},
	{13, L"w", &ft_fractol_key_up},
	{0, L"a", &ft_fractol_key_left},
	{2, L"d", &ft_fractol_key_right},
	{1, L"s", &ft_fractol_key_down},
	{49, L"space_bar", &ft_fractol_space},
	{38, L"J", &ft_fractol_select_julia},
	{46, L"M", &ft_fractol_select_mandelbrot},
	{11, L"B", &ft_fractol_select_burning_ship},
	{82, L"0", &ft_fractol_select_bonus_0},
	{83, L"1", &ft_fractol_select_bonus_1},
	{84, L"2", &ft_fractol_select_bonus_2}
};

#endif
