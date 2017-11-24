/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:53:57 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/16 17:43:59 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include "ft_string.h"
#include <wchar.h>

static void	ft_printf_handle_string_add_wchar(char **p, wchar_t wc)
{
	if (wc < 0x80)
		*((*p)++) = ((wc >> 0x00) & 0x7f) | 0x00;
	else if (wc < 0x0800)
	{
		*((*p)++) = ((wc >> 0x06) & 0x1f) | 0xc0;
		*((*p)++) = ((wc >> 0x00) & 0x3f) | 0x80;
	}
	else if (wc < 0x010000)
	{
		*((*p)++) = ((wc >> 0x0c) & 0x0f) | 0xe0;
		*((*p)++) = ((wc >> 0x06) & 0x3f) | 0x80;
		*((*p)++) = ((wc >> 0x00) & 0x3f) | 0x80;
	}
	else if (wc < 0x110000)
	{
		*((*p)++) = ((wc >> 0x12) & 0x07) | 0xf0;
		*((*p)++) = ((wc >> 0x0c) & 0x3f) | 0x80;
		*((*p)++) = ((wc >> 0x06) & 0x3f) | 0x80;
		*((*p)++) = ((wc >> 0x00) & 0x3f) | 0x80;
	}
}

void		ft_printf_handle_string(char **p, t_printf_syntax *pf, va_list ap)
{
	char	*s1;
	wchar_t	*s2;
	size_t	n;
	size_t	i;

	i = 0;
	if (pf->qualifier == 'l')
	{
		if ((s2 = (void *)va_arg(ap, wchar_t *)) == NULL)
			s2 = L"(null)";
		n = wcsnlen(s2, pf->precision);
		ft_printf_prepadd(p, n, pf);
		while (i++ < n)
			ft_printf_handle_string_add_wchar(p, *s2++);
	}
	else
	{
		if ((s1 = (void *)va_arg(ap, char *)) == NULL)
			s1 = "(null)";
		n = ft_strnlen(s1, pf->precision);
		ft_printf_prepadd(p, n, pf);
		while (i++ < n)
			*((*p)++) = *s1++;
	}
	ft_printf_postpadd(p, n, pf);
}
