/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:03:27 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/19 00:20:15 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

void				ft_putstr_fd(char const *str, int fd);
void				ft_putstr(char const *str);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbr(int c);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putendl(char const *str);
void				ft_putchar_fd(int c, int fd);
void				ft_putchar(int c);
void				ft_putnstr(const char *str, int len);

#endif
