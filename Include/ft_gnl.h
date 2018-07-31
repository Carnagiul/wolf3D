/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:05:01 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/28 07:40:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# define BUFF_SIZE	32
# define MAX_FD		1000

typedef struct		s_files
{
	int				fd;
	char			*new;
	size_t			size;
	unsigned int	passage;
}					t_files;

int					get_next_line(int fd, char **line);
char				*ft_get_content_file(char *file);
char				*ft_get_content_file_fd(int fd);
char				*ft_get_extension(char *str);

#endif
