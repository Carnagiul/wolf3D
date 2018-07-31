/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:32:05 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/10 14:52:17 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# define ERROR_MSG_DISPLAY "ERROR"
# define ERROR_CUSTOM_MSG 1

int					ft_atoi(char const *str);
char				*ft_itoa(int nb);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa_base(int nb, int base);
int					ft_atoi_base(char *str, int base);
void				*ft_malloc(size_t size);
void				ft_exit_error(void);
void				ft_init_exit_error(void);
void				free_char_ss(char **str);

#endif
