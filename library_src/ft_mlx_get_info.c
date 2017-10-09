/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_get_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 04:44:37 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:22:31 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			*ft_mlx_get_size(char *argv, int *d)
{
	char	**split;
	int		i;

	split = ft_strsplit(argv, 'x');
	i = 0;
	while (split[i])
	{
		if (i == 0)
			d[0] = ft_atoi(split[i]);
		else if (i == 1)
			d[1] = ft_atoi(split[i]);
		else
		{
			ft_printf("Erreur: trop de parametres pour la taille");
			ft_printf(" de la fenetre\n");
			ft_printf("--size [WIDTH]x[HEIGHT]\n");
		}
		i++;
	}
	ft_strdel_array(split);
	return (d);
}

int			*ft_mlx_extended_parser(int argc, char **argv)
{
	int		i;
	int		*d;

	i = 2;
	d = (int *)ft_malloc(sizeof(int) * 2);
	if (!d)
		exit(ft_printf("Error: ft_mlx_extended_parser\n"));
	d[0] = 1280;
	d[1] = 720;
	if (argc <= 2)
		return (d);
	if (argc % 2 != 0)
		return (d);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--size") == 0)
			d = ft_mlx_get_size(argv[i + 1], d);
		i += 2;
	}
	d[0] = (d[0] < 1280) ? 1280 : d[0];
	d[1] = (d[1] < 720) ? 720 : d[1];
	return (d);
}
