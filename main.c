/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 07:40:08 by piquerue          #+#    #+#             */
/*   Updated: 2018/05/28 07:40:09 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	managecmd(char **argv, int argc)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--load_new_file") == 0)
			ft_printf("Merci d'indiquer un nom de fichier\n");
		i++;
	}
}

int			main(int argc, char **argv)
{
	ft_init_exit_error();
	managecmd(argv, argc)
	_exit(0);
}
