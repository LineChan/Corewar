/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_unsigned.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 03:00:55 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/16 17:44:02 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

void	ft_printf_handle_unsigned(char **p, t_printf_syntax *pf, va_list ap)
{
	uint64_t n;

	if ('H' == pf->qualifier)
		n = (uint64_t)(uint8_t)va_arg(ap, int);
	else if ('h' == pf->qualifier)
		n = (uint64_t)(uint16_t)va_arg(ap, int);
	else if ('L' == pf->qualifier || 'l' == pf->qualifier)
		n = (uint64_t)va_arg(ap, uint64_t);
	else if ('z' == pf->qualifier)
		n = (uint64_t)(size_t)va_arg(ap, uint64_t);
	else if ('j' == pf->qualifier)
		n = (uint64_t)(uintmax_t)va_arg(ap, uint64_t);
	else
		n = (uint64_t)(uint32_t)va_arg(ap, int);
	if (pf->flags & FT_P_LEFT)
		pf->flags &= ~FT_P_ZEROPAD;
	if (pf->base >= 2 && pf->base <= 36)
		ft_printf_handle_integer(p, pf, n);
}
