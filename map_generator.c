/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 07:19:55 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/22 07:25:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	int fd;
	int y_size;
	int x_size;
	int i;
	int j;

	if (argc == 3)
	{
		y_size = ft_atoi(argv[1]);
		x_size = ft_atoi(argv[2]);
		system("rm -f map.gen");
		fd = open("map.gen", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		ft_putnbr_fd(y_size, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(x_size, fd);
		write(fd, "\n", 1);
		i = 0;
		while (i < y_size)
		{
			j = 0;
			while (j < x_size)
			{
				if (i == 0 || j == 0 || i == y_size - 1 || j == x_size - 1)
					write(fd, "1", 1);
				else
				{
					int n = rand() % 2;
					int n2 = rand() % 2;
					int n3 = rand() % 2;
					(n == 1 && n2 == 1 && n3 == 1) ? write(fd, "1", 1) : write(fd, "0", 1);
				}
				(j + 1 == x_size) ? write(fd, "\n", 1) : write(fd, " ", 1);
				j++;
			}
			i++;
		}
		write(1,"its ok\n",7);
		close(fd);
	}
}
