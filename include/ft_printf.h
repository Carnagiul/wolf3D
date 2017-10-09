/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 21:03:03 by piquerue          #+#    #+#             */
/*   Updated: 2017/06/01 02:22:18 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRINTF_COLOR_ON	1
# define PRINTF_HELP_ON		0
# define PRINTF_DEBEUG_ON	0
# define PRINTF_CONSOLE_ON	0
# define FT_PRINTF_MAJB		0

typedef	struct			s_precis
{
	int					before;
	char				first;
	char				error_first;
	int					is_signed;
	int					before_display;
	int					precis;
	int					limits;
	int					dot_found;
	int					after_display;
}						t_precis;

typedef	struct			s_color
{
	char				*red;
	char				*blue;
	char				*green;
	char				*yellow;
	char				*cyan;
	char				*purple;
	char				*eof;
	char				*white;
	char				*black;
}						t_color;

typedef struct			s_flags
{
	int					h;
	int					l;
	int					ll;
	int					j;
	int					z;
	int					dieze;
	int					space;
	int					dollard;
}						t_flags;

typedef struct			s_print
{
	int					i;
	int					writed;
	int					width;
	int					len;
	int					len_found;
	t_flags				*flags;
	t_precis			*precision;
	t_color				*color;
	va_list				va_cpy;
}						t_print;

typedef struct			s_itoa
{
	unsigned long long	nbr;
	int					is_signed;
	int					base_len;
	int					is_maj;
	char				*ret;
	char				*base;
}						t_itoa;

typedef struct			s_printf
{
	char				c;
	void				(*f)(char c, ...);
}						t_printf;

/*
** FT_DISPLAY.C
*/

char					*ft_precision_first(t_print *print, char *ret, char *d);

char					*ft_precision_end(t_print *print, char *ret,
		t_itoa *itoa, char *d);

void					ft_mid(t_print *print, char **ret, char **d,
		t_itoa *itoa);

char					*ft_precision_mid(t_print *print, char *ret,
		t_itoa *itoa, char *d);

char					*ft_precision_first_start(t_print *print, char *ret);

/*
** FT_INIT_STRUCTS.C
*/

t_color					*init_color(void);

t_flags					*ft_init_flags(void);

t_precis				*ft_init_precision(void);

t_print					*ft_init_printf(void);

/*
** FT_ITOA_STRUCT.C
*/

t_itoa					*k_itoa_k(t_print *print,
		unsigned long long nbr, int is_signed, char c);

unsigned long long		ft_pow_llu(t_itoa *itoa);

void					ft_gen_base(t_itoa *itoa);

/*
** FT_PARSER_CHECKER.C
*/

int						ft_char_is_delimiteur(const char c);

void					ft_parser_checker_2(char const c, t_print *print,
		const char c_1);

void					ft_parser_checker(char const c, t_print *print,
		const char c_1);

void					ft_delimite_parser_2(t_print *print,
		const char *format, va_list *vl);

void					ft_delimite_parser(t_print *print, const char *format,
		va_list *vl);

/*
** FT_PRINTF.C
*/

void					ft_getmax_print(t_print *print, int len, int first);

int						ft_printf(const char *format, ...);

void					test(int result, int result2);

/*
** FT_PRINTF_INT.C
*/

void					ft_printf_int(t_print *print, va_list *vl);

/*
** FT_PRINTF_ITOA.C
*/

void					ft_printf_itoa(t_print *print, const char *format,
		va_list *vl);

/*
** FT_PRINTF_N.C
*/

void					ft_printf_n(int *nb, t_print *print);

/*
** FT_PRINTF_PERCENT.C
*/

void					ft_parser_percent_2(const char *format, t_print *print,
		va_list *vl);

void					ft_parser_percent(const char *format, t_print *print,
		va_list *vl);

/*
** FT_PRINTF_P.C
*/

void					ft_printf_p(void *addr, t_print *print);

/*
** FT_PRINTF_STR.C
*/

void					ft_printf_str_s2(t_print *print, char *str);

void					ft_printf_str(t_print *print, const char *format,
		va_list *vl);

/*
** FT_PRINTF_UINT.C
*/

void					ft_printf_lluint(t_print *print, va_list *vl);

void					ft_printf_uint(t_print *print, va_list *vl);

/*
** FT_PRINTF_DISPLAY.C
*/

void					ft_print_char(t_print *print, int c);

void					ft_putwstr(const wchar_t *str, t_print *print);

int						ft_howputnstr(wchar_t *str, int len, t_print *print);

void					ft_putwnstr(wchar_t *str, int len, t_print *print);

void					ft_putwchar(int wc, t_print *print);

/*
** FT_PRINTF_PARSER_CHECKER_1.c
*/

void					ft_printf_parser_digit(char c, ...);

void					ft_printf_parser_flags(char c, ...);

void					ft_printf_parser_specs(char c, ...);

/*
** FT_PRINTF_STRING.C
*/

void					ft_printf_string(t_print *print);

void					ft_printf_str_s(t_print *print, va_list *vl);

void					ft_printf_str_ls(t_print *print, va_list *vl);

/*
** FT_FREE_ITOA.C
*/

void					ft_free_itoa(t_itoa *itoa);

void					ft_free_print(t_print *print);

char					*ft_free_join1(char *ret, char *e);

char					*ft_free_join2(char *ret, char *e);

char					*ft_free_join(char *f, char *f2);

/*
** FT_PRINTF_DOUBLE.C
*/

void					ft_printf_double(t_print *print, va_list *vl, char c);

/*
** FT_PRINTF_DOLLARD.C
*/

void					ft_printf_dollard(t_print *print, const char *format);

/*
** FT_PRINTF_COLOR.C
*/

void					ft_printf_color(t_print *print, const char *format);

/*
** FT_PRINTF_HELP.C
*/

void					ft_printf_help(t_print *print);

void					ft_debeug_in_console(char *c, t_print *print,
		char *ret, char *d);

/*
** FT_PRINT_DEBEUG.C
*/

void					ft_printf_debeug(t_print *print);

#endif
