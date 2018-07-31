/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 02:15:42 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/10 14:50:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_get_content_file_fd(int fd)
{
	char	*content;
	char	*gnl;

	if (fd >= 0)
	{
		content = ft_strnew(1);
		while (get_next_line(fd, &gnl) == 1)
		{
			content = ft_free_join1(content, gnl);
			content = ft_free_join1(content, "\n");
			ft_strdel(&gnl);
		}
		close(fd);
		return (content);
	}
	ft_printf("Error: can't open the file @R%d@@\n", fd);
	return (NULL);
}

char		*ft_get_content_file(char *file)
{
	int		fd;
	char	*content;
	char	*gnl;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd >= 1)
	{
		content = ft_strnew(1);
		while ((ret = get_next_line(fd, &gnl)) == 1)
		{
			content = ft_free_join1(content, gnl);
			content = ft_free_join1(content, "\n");
			ft_strdel(&gnl);
		}
		if (ret == -1)
			exit(0);
		close(fd);
		return (content);
	}
	ft_printf("Error: can't open the file @R%s@@\n", file);
	return (NULL);
}
