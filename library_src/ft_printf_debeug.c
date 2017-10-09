/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_debeug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 02:50:58 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/21 02:59:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_debeug(t_print *print)
{
	ft_printf("\nMode debeug : \n");
	ft_printf("Caractere afficher : %d\n", print->writed);
	ft_printf("Position de i : %d\n", print->i);
	print->i++;
}
