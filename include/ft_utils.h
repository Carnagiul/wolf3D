/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:32:05 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:05:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

int					ft_atoi(char const *str);
char				*ft_itoa(int nb);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa_base(int nb, int base);
int					ft_atoi_base(char *str, int base);

void				ft_malloc_finder1(char *to_find);
double				*ft_utils_init_double_array(int rows);
void				*ft_malloc(size_t size);

#endif
