/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_roman.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:48:51 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/16 17:41:01 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

static void		ft_printf_handle_roman_engine(
					char **p,
					uint16_t *n,
					uint16_t u,
					char const *s)
{
	char const *r;

	while (*n >= u)
	{
		r = s;
		while (*r != 0)
			*((*p)++) = *r++;
		*n -= u;
	}
}

void			ft_printf_handle_roman(
					char **p,
					t_printf_syntax *pf,
					va_list ap)
{
	uint16_t n;

	n = (uint16_t)va_arg(ap, int);
	if ('l' != pf->qualifier)
		n = (uint16_t)(uint8_t)n;
	ft_printf_prepadd(p, 0, pf);
	if (n == 0)
	{
		*((*p)++) = '0';
		ft_printf_postpadd(p, 0, pf);
		return ;
	}
	ft_printf_handle_roman_engine(p, &n, 1000, "M");
	ft_printf_handle_roman_engine(p, &n, 900, "CM");
	ft_printf_handle_roman_engine(p, &n, 500, "D");
	ft_printf_handle_roman_engine(p, &n, 400, "CD");
	ft_printf_handle_roman_engine(p, &n, 100, "C");
	ft_printf_handle_roman_engine(p, &n, 90, "XC");
	ft_printf_handle_roman_engine(p, &n, 50, "L");
	ft_printf_handle_roman_engine(p, &n, 40, "XL");
	ft_printf_handle_roman_engine(p, &n, 10, "X");
	ft_printf_handle_roman_engine(p, &n, 9, "IX");
	ft_printf_handle_roman_engine(p, &n, 5, "V");
	ft_printf_handle_roman_engine(p, &n, 4, "IV");
	ft_printf_handle_roman_engine(p, &n, 1, "I");
	ft_printf_postpadd(p, 0, pf);
}
