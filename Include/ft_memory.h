/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:14:08 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:16:35 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

void				*ft_memset(void *ptr, int value, size_t size);
void				*ft_memmove(void *dest, void const *src, size_t len);
void				ft_memdel(void **pt);
void				*ft_memcpy(void *dest, void const *src, size_t size);
int					ft_memcmp(void const *s1, void const *s2, size_t len);
char				*ft_memchr(void const *src, int c, size_t len);
void				*ft_memccpy(void *dest, void const *src, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *ptr, size_t size);

#endif
