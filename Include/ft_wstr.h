/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:14:37 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/19 00:28:08 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WSTR_H
# define FT_WSTR_H

typedef struct	s_unix_char_limit
{
	int			min;
	int			max;
	char		*name;
}				t_unix_char_limit;

size_t			ft_wcharlen(int wc);
size_t			ft_wstrlen(wchar_t *str);
void			ft_putwstr(const wchar_t *str, t_print *print);
char			*ft_unix_string_get_name(int wc);
int				ft_unix_char_is_valid(int wc);
void			ft_unix_string_display_put_struct(t_unix_char_limit l);
void			ft_unix_string_display_put(void);
int				ft_unix_string_display_ii(int wc);
int				ft_unix_string_display_iii(int wc);
int				ft_unix_string_display_iv(int wc);
int				ft_unix_char_is_display_ii(int wc);
int				ft_unix_char_is_display_iii(int wc);
int				ft_unix_char_is_display_iv(int wc);

#endif
