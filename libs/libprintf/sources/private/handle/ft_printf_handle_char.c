/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:53:57 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 16:55:40 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include <wchar.h>

static void	ft_printf_handle_char_add_wchar(char **p, wchar_t wc)
{
	if (wc < 0x80)
		*((*p)++) = wc & 0x7f;
	else if (wc < 0x0800)
	{
		*((*p)++) = ((wc >> 0x06) & 0x1f) | 0xc0;
		*((*p)++) = (wc & 0x3f) | 0x80;
	}
	else if (wc < 0x010000)
	{
		*((*p)++) = ((wc >> 0x0c) & 0x0f) | 0xe0;
		*((*p)++) = ((wc >> 0x06) & 0x3f) | 0x80;
		*((*p)++) = (wc & 0x3f) | 0x80;
	}
	else if (wc < 0x110000)
	{
		*((*p)++) = ((wc >> 0x12) & 0x07) | 0xf0;
		*((*p)++) = ((wc >> 0x0c) & 0x3f) | 0x80;
		*((*p)++) = ((wc >> 0x06) & 0x3f) | 0x80;
		*((*p)++) = (wc & 0x3f) | 0x80;
	}
}

void		ft_printf_handle_char(char **p, t_printf_syntax *pf, va_list ap)
{
	ft_printf_prepadd(p, 1, pf);
	if ('l' == pf->qualifier)
		ft_printf_handle_char_add_wchar(p, (wchar_t)va_arg(ap, wchar_t));
	else
		*((*p)++) = (uint8_t)va_arg(ap, int);
	ft_printf_postpadd(p, 1, pf);
}
