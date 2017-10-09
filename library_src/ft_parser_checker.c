/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 05:30:09 by piquerue          #+#    #+#             */
/*   Updated: 2017/10/09 18:06:05 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../include/ft_printf_mappeur.h"

int		ft_char_is_delimiteur(const char c)
{
	if (c == 'l' || c == '#' || c == 'h' || c == 'j' || c == 'z' || c == '.' ||
		c == '+' || c == '-' || (c > '/' && c < ':') || c == ' ' || c == '*' ||
		c == '$' || c == 'L')
		return (0);
	if (c == '\0')
		return (-1);
	if (c == 's' || c == 'd' || c == 'i' || c == 'S' || c == 'c' || c == 'C' ||
			c == '%' || c == 'x' || c == 'X' || c == 'O' || c == 'o' ||
			c == 'p' || c == 'u' || c == 'U' || c == 'D' || c == 'n' ||
			c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' ||
			c == 'G' || c == 'a' || c == 'A' || c == 'b')
		return (1);
	return (-1);
}

void	ft_parser_checker(char const c, t_print *print, const char c2)
{
	int i;

	i = 0;
	while (i < 21)
	{
		if (c == g_t_printf[i].c)
			return (g_t_printf[i].f(c, print, c2));
		i++;
	}
}

void	ft_delimite_parser_2(t_print *print, const char *format, va_list *vl)
{
	if (format[print->i] == 'p')
		ft_printf_p(va_arg(*vl, void *), print);
	if (format[print->i] == 'n')
		ft_printf_n(va_arg(*vl, int *), print);
	if (format[print->i] == 'a' || format[print->i] == 'A' ||
			format[print->i] == 'e' || format[print->i] == 'E' ||
			format[print->i] == 'f' || format[print->i] == 'F' ||
			format[print->i] == 'g' || format[print->i] == 'G')
		ft_printf_double(print, vl, format[print->i]);
}

void	ft_parser_check_flags(t_print *print)
{
	if (print->flags->l == 2 || print->flags->j == 1 || print->flags->z == 1)
	{
		print->flags->h = 0;
		print->flags->l = 2;
		print->flags->j = 0;
		print->flags->z = 0;
	}
	else if (print->flags->l == 1)
	{
		print->flags->h = 0;
		print->flags->l = 1;
		print->flags->j = 0;
		print->flags->z = 0;
	}
	if (print->flags->h > 2 || print->flags->dieze > 1 || print->flags->j > 1 ||
			print->flags->z > 1 || print->flags->l > 2 || print->flags->ll > 1)
	{
		print->flags->h = 0;
		print->flags->l = 0;
		print->flags->j = 0;
		print->flags->z = 0;
		print->flags->dieze = 0;
	}
}

void	ft_delimite_parser(t_print *print, const char *format, va_list *vl)
{
	ft_parser_check_flags(print);
	if (format[print->i] == 'd' || format[print->i] == 'i')
		ft_printf_int(print, vl);
	if (format[print->i] == 's' || format[print->i] == 'c' ||
			format[print->i] == 'S' || format[print->i] == 'C')
		ft_printf_str(print, format, vl);
	if (format[print->i] == 'x' || format[print->i] == 'X' ||
			format[print->i] == 'o' || format[print->i] == 'O' ||
			format[print->i] == 'b')
		ft_printf_itoa(print, format, vl);
	if (format[print->i] == '%')
		ft_print_char(print, '%');
	if (format[print->i] == 'u')
		ft_printf_uint(print, vl);
	if (format[print->i] == 'U')
		ft_printf_lluint(print, vl);
	if (format[print->i] == 'D')
	{
		print->flags->h = 0;
		print->flags->l = 2;
		print->flags->j = 0;
		print->flags->z = 0;
		ft_printf_int(print, vl);
	}
	ft_delimite_parser_2(print, format, vl);
}
