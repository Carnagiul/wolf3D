/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 01:32:28 by piquerue          #+#    #+#             */
/*   Updated: 2017/07/10 00:41:12 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

typedef struct	s_img
{
	char		*img;
	int			bits_per_pixel;
	int			endian;
	int			size_line;
	void		*img_ptr;
	int			width;
	int			height;
}				t_img;

typedef struct	s_win
{
	void		*win;
	void		*mlx;
	double		x;
	double		y;
	int			width;
	int			height;
	char		*name;
}				t_win;

typedef struct	s_keycode_mlx
{
	int			keycode;
	char		*key;
}				t_keycode_mlx;

t_img			*ft_mlx_extended_gen_img(t_win *win);
t_img			*ft_mlx_extended_gen_imgxpm(t_win *win, char *name);
t_win			*ft_mlx_extended_gen_win(int width, int height, char *name);

int				*ft_mlx_get_size(char *argv, int *d);
int				*ft_mlx_extended_parser(int argc, char **argv);

void			display_menu(t_fractol *fractol);

t_color_mlx		create_color(int red, int green, int blue);
void			ft_sphere(t_fractol *fractol, t_point pt, int r);
t_color_mlx		create_color(int red, int green, int blue);

void			ft_pixel_put(t_fractol *fractol, t_point pt);
void			ft_pixel_put3(t_fractol *fractol, t_point pt,
		t_color_mlx color);

t_texture		*ft_mlx_load_texture(char *file, t_win *win);

void			free_t_img(t_img *img, t_win *win);
void			free_t_win(t_win *win);
#endif
