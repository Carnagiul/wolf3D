/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 03:16:53 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/30 05:39:19 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_MAP_H
# define FT_FDF_MAP_H

# define Q 12
# define W 13
# define E 14
# define R 15
# define T 17
# define Y 16
# define U 32
# define I 34
# define O 31
# define P 35

# define A 0
# define S 1
# define D 2
# define F 3
# define G 5
# define H 4
# define J 38
# define K 40
# define L 37

# define Z 6
# define X 7
# define C 8
# define V 9
# define B 11
# define N 45
# define M 46

# define SPACE 49

# define N0 82
# define N1 83
# define N2 84
# define N3 85
# define N4 86
# define N5 87
# define N6 88
# define N7 89
# define N8 91
# define N9 92

# define SLASH 75
/*
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
*/
t_keycode_mlx g_t_keycode[] = {
	{Q, "q"},
	{W, "w"},
	{E, "e"},
	{R, "r"},
	{T, "t"},
	{Y, "y"},
	{U, "u"},
	{I, "i"},
	{O, "o"},
	{P, "p"},
	{A, "a"},
	{S, "s"},
	{D, "d"},
	{F, "f"},
	{G, "g"},
	{H, "h"},
	{J, "j"},
	{K, "k"},
	{L, "l"},
	{Z, "z"},
	{X, "x"},
	{C, "c"},
	{V, "v"},
	{B, "b"},
	{N, "n"},
	{M, "m"},
	{SPACE, " "},
	{SLASH, "/"},
	{N0, "0"},
	{N1, "1"},
	{N2, "2"},
	{N3, "3"},
	{N4, "4"},
	{N5, "5"},
	{N6, "6"},
	{N7, "7"},
	{N8, "8"},
	{N9, "9"},
};
#endif
