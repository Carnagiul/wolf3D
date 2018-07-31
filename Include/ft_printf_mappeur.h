/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mappeur.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 04:03:51 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/21 03:07:22 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MAPPEUR_H
# define FT_PRINTF_MAPPEUR_H

t_printf	g_t_printf[] = {
	{'0', &ft_printf_parser_digit},
	{'1', &ft_printf_parser_digit},
	{'2', &ft_printf_parser_digit},
	{'3', &ft_printf_parser_digit},
	{'4', &ft_printf_parser_digit},
	{'5', &ft_printf_parser_digit},
	{'6', &ft_printf_parser_digit},
	{'7', &ft_printf_parser_digit},
	{'8', &ft_printf_parser_digit},
	{'9', &ft_printf_parser_digit},
	{'h', &ft_printf_parser_flags},
	{'l', &ft_printf_parser_flags},
	{'j', &ft_printf_parser_flags},
	{'z', &ft_printf_parser_flags},
	{'#', &ft_printf_parser_flags},
	{' ', &ft_printf_parser_flags},
	{'$', &ft_printf_parser_flags},
	{'L', &ft_printf_parser_flags},
	{'+', &ft_printf_parser_specs},
	{'-', &ft_printf_parser_specs},
	{'.', &ft_printf_parser_specs}
};

#endif
