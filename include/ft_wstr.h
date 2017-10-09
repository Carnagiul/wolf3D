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

size_t	ft_wcharlen(int wc);
size_t	ft_wstrlen(wchar_t *str);
void	ft_putwstr(const wchar_t *str, t_print *print);

#endif
