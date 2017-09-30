/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_signed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 03:00:55 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 15:47:29 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

void		ft_printf_handle_signed(char **p, t_printf_syntax *pf, va_list ap)
{
	int64_t n;

	if ('H' == pf->qualifier)
		n = (int64_t)(int8_t)va_arg(ap, int);
	else if ('h' == pf->qualifier)
		n = (int64_t)(int16_t)va_arg(ap, int);
	else if ('L' == pf->qualifier || 'l' == pf->qualifier)
		n = (int64_t)va_arg(ap, int64_t);
	else if ('z' == pf->qualifier)
		n = (int64_t)(size_t)va_arg(ap, int64_t);
	else if ('j' == pf->qualifier)
		n = (int64_t)(intmax_t)va_arg(ap, int64_t);
	else
		n = (int64_t)(int32_t)va_arg(ap, int);
	pf->flags |= FT_P_SIGN;
	if (n < 0)
	{
		n = -n;
		pf->flags |= FT_P_NEGATIV;
	}
	if (pf->flags & FT_P_LEFT)
		pf->flags &= ~FT_P_ZEROPAD;
	if (pf->base >= 2 && pf->base <= 36)
		ft_printf_handle_integer(p, pf, n);
}
