/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 03:17:20 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/30 00:02:22 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char			*strjoin(char *new, char *buff)
{
	char			*tmp;

	if (!(tmp = ft_strjoin(new, buff)))
		return (NULL);
	free(new);
	new = NULL;
	return (tmp);
}

char				*ft_stock_the_new_line(char *str)
{
	int				i;
	int				len;
	char			*new;

	i = 0;
	len = 0;
	while (str[len++])
		;
	if (!(new = (char *)malloc(sizeof(*new) * len + 1)))
		return (NULL);
	while (i < len && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char			*ft_clean_new(char *str, int fd, t_gnl files[MAX_FD])
{
	char			*new;
	int				i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	new = ft_strdup(str + i + 1);
	ft_strdel(&str);
	if (files[fd].size)
		files[fd].size += ft_strlen(new);
	else
		files[fd].size = ft_strlen(new);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static t_gnl	files[MAX_FD];

	if (BUFF_SIZE < 0 || !line || fd > MAX_FD || fd < 0)
		return (-1);
	if (!files[fd].new)
		files[fd].new = ft_strnew(1);
	ret = 2;
	while (!(ft_strchr(files[fd].new, '\n')))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		files[fd].new = strjoin(files[fd].new, buff);
		if (ret == 0 && *(files[fd].new) == '\0')
			return (0);
		if (ret == 0)
			break ;
	}
	*line = ft_stock_the_new_line(files[fd].new);
	files[fd].passage++;
	files[fd].new = ft_clean_new(files[fd].new, fd, files);
	return (1);
}
