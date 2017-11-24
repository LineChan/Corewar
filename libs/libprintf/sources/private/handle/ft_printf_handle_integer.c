/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 03:00:55 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 16:09:17 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

static void		ft_printf_insert_sign(
					char **p,
					t_printf_syntax *pf,
					char sign,
					char *s)
{
	if (!(pf->flags & (FT_P_ZEROPAD | FT_P_LEFT)))
	{
		if (pf->flags & FT_P_HEXPREP)
		{
			if (8 == pf->base)
				--pf->width;
			else if (16 == pf->base)
				pf->width -= 2;
		}
		while (pf->width-- > 0)
			*((*p)++) = ' ';
	}
	if (0 != sign)
		*((*p)++) = sign;
	if (!(pf->flags & FT_P_HEXPREP))
		return ;
	if (8 == pf->base || 16 == pf->base)
	{
		--pf->width;
		*((*p)++) = '0';
	}
	if (16 != pf->base)
		return ;
	--pf->width;
	*((*p)++) = s[33];
}

static char		ft_printf_insert_routine(
					char **p,
					uint64_t m,
					t_printf_syntax *pf,
					char *dgt)
{
	char sign;

	sign = 0;
	if (pf->flags & FT_P_SIGN)
	{
		if (pf->flags & (FT_P_NEGATIV | FT_P_PLUS | FT_P_SPACE))
			--pf->width;
		if (pf->flags & FT_P_NEGATIV)
			sign = '-';
		else if (pf->flags & FT_P_PLUS)
			sign = '+';
		else if (pf->flags & FT_P_SPACE)
			sign = ' ';
	}
	if (0 != m)
	{
		while (0 != m)
		{
			*((*p)++) = *(dgt + (m % pf->base));
			m /= pf->base;
		}
	}
	else
		*((*p)++) = '0';
	return (sign);
}

void			ft_printf_handle_integer(
					char **p,
					t_printf_syntax *pf,
					uint64_t n)
{
	char		tmp[100];
	char		*digit;
	char		sign;
	char		*s;
	int			i;

	digit = (pf->flags & FT_P_UPPERCASE) ? FT_P_UPPER_DIGIT : FT_P_LOWER_DIGIT;
	s = tmp;
	sign = ft_printf_insert_routine(&s, n, pf, digit);
	i = s - tmp;
	if (i > pf->precision)
		pf->precision = i;
	pf->width -= pf->precision;
	ft_printf_insert_sign(p, pf, sign, digit);
	ft_printf_prepadd(p, 0, pf);
	while (i < pf->precision--)
		*((*p)++) = '0';
	while (i-- > 0)
		*((*p)++) = tmp[i];
	ft_printf_postpadd(p, 0, pf);
}
