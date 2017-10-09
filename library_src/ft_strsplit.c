/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:26:59 by piquerue          #+#    #+#             */
/*   Updated: 2017/08/28 02:24:38 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		ft_nbword(char const *s, char c)
{
	int			i;
	int			isword;

	i = 0;
	isword = 0;
	while (*s)
	{
		if (isword == 0 && *s != c)
		{
			isword = 1;
			i++;
		}
		else if (isword == 1 && *s == c)
			isword = 0;
		s++;
	}
	return (i);
}

static int		ft_length(char const *s, char c)
{
	int			length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	int			nbword;

	i = 0;
	if (!s)
		return (0);
	nbword = ft_nbword(s, c);
	tab = (char **)ft_malloc(sizeof(char *) * (nbword + 1));
	if (!tab)
		exit(0);
	while (nbword--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strsub(s, 0, ft_length(s, c));
		if (!tab[i])
			exit(0);
		s = s + ft_length(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
