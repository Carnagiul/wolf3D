/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:11:51 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/22 08:52:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <pthread.h>

typedef struct			s_color_mlx
{
	int					red;
	int					green;
	int					blue;
}						t_color_mlx;

typedef struct			s_fractol
{
	struct s_win		*win;
	struct s_img		*img;
	int					iteration_max;
	double				zoom;
	double				move_x;
	double				move_y;
	double				zoom_i;
	double				zoom_r;
	int					alive;
	int					space;
	int					fractal;
	struct s_color_mlx	color_bg;
	struct s_color_mlx	color_pt;
	struct s_complex	z;
	int					menu;
	int					id;
}						t_fractol;

typedef struct			s_fdf_map
{
	int					key;
	wchar_t				*key_display;
	void				(*f)(t_fractol *fractol);
}						t_fdf_map;

void	ft_wolf_init(char **argv);

#endif
