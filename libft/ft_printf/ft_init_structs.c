/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 05:28:08 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/22 01:49:42 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color			*init_color(void)
{
	t_color		*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->eof = "\033[37m";
	color->black = "\033[30m";
	color->blue = "\033[34m";
	color->green = "\033[32m";
	color->cyan = "\033[36m";
	color->purple = "\033[35m";
	color->red = "\033[31m";
	color->white = "\033[37m";
	color->yellow = "\033[33m";
	return (color);
}

t_flags			*ft_init_flags(void)
{
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->h = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->dollard = 0;
	flags->j = 0;
	flags->z = 0;
	flags->dieze = 0;
	flags->space = 0;
	return (flags);
}

t_precis		*ft_init_precision(void)
{
	t_precis	*precis;

	precis = (t_precis *)malloc(sizeof(t_precis));
	if (!precis)
		return (NULL);
	precis->before = 0;
	precis->first = ' ';
	precis->error_first = 0;
	precis->is_signed = 0;
	precis->before_display = 0;
	precis->precis = 0;
	precis->limits = 0;
	precis->dot_found = 0;
	precis->after_display = 0;
	return (precis);
}

t_print			*ft_init_printf(void)
{
	t_print		*print;

	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (NULL);
	print->i = 0;
	print->writed = 0;
	print->len = 0;
	print->len_found = 0;
	print->width = 0;
	print->flags = ft_init_flags();
	print->precision = ft_init_precision();
	print->color = init_color();
	return (print);
}
