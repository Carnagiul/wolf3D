/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:37:22 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:39:57 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

char	*ft_strtrim(char const *str);
char	*ft_strsub(char const *s, unsigned int rem, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(char const *str, char const *to_find);
char	*ft_strnstr(char const *str, char const *to_find, size_t len);
char	*ft_strdup(char const *str);
char	*ft_strnew(size_t size);
int		ft_strnequ(char const *s1, char const *s2, size_t len);
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strncpy(char *dest, char const *src, size_t n);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, unsigned int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strmap(char const *s, char (*f)(char));
size_t	ft_strlen(char const *str);
char	*ft_strcat(char *dest, char const *src);
char	*ft_strncat(char *dest, char const *src, int nb);
size_t	ft_strlcat(char *dest, char const *src, size_t size);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
void	ft_striter(char *str, void (*f)(char *));
void	ft_strdel(char **str);
char	*ft_strcpy(char *dest, char const *src);
void	ft_strclr(char *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strrchr(char const *str, int c);
char	*ft_string_capitalize(char *str);
char	*ft_reverse(char *str);

#endif
