/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 02:30:36 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/31 05:09:39 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_itoa(t_itoa *itoa)
{
	if (!itoa)
		return ;
	free(itoa->ret);
	free(itoa->base);
	free(itoa);
	itoa = NULL;
}

void		ft_free_print(t_print *print)
{
	if (!print)
		return ;
	free(print->flags);
	free(print->precision);
	free(print->color);
	free(print);
	print = NULL;
}

char		*ft_free_join1(char *ret, char *e)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(ret, e)))
		return (NULL);
	free(ret);
	ret = NULL;
	return (tmp);
}

char		*ft_free_join2(char *ret, char *e)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(ret, e)))
		return (NULL);
	free(e);
	e = NULL;
	return (tmp);
}

char		*ft_free_join(char *f, char *f2)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(f, f2)))
		return (NULL);
	free(f);
	free(f2);
	f = NULL;
	f2 = NULL;
	return (tmp);
}
