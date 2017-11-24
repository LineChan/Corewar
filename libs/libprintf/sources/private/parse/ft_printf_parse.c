/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:35:06 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 16:15:24 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include <string.h>
#include <ctype.h>

static void	ft_printf_parse_precision(
				char const **s,
				t_printf_syntax *pf,
				va_list ap)
{
	++(*s);
	if ('*' == **s)
	{
		++(*s);
		pf->precision = (int)va_arg(ap, int);
	}
	else
	{
		pf->precision = 0;
		while (isdigit(**s))
			pf->precision = pf->precision * 10 + *((*s)++) - '0';
	}
}

static void	ft_printf_parse_width(
				char const **s,
				t_printf_syntax *pf,
				va_list ap)
{
	int i;

	if ('*' == **s)
	{
		++(*s);
		i = va_arg(ap, int);
		if (i >= 0)
			pf->width = i;
		else if (i < 0)
		{
			pf->width = -i;
			pf->flags |= FT_P_LEFT;
		}
	}
	else
	{
		pf->width = 0;
		while (isdigit(**s))
			pf->width = pf->width * 10 + *((*s)++) - '0';
	}
}

static void	ft_printf_parse_flags(char c, t_printf_syntax *pf)
{
	if ('-' == c)
		pf->flags |= FT_P_LEFT;
	else if ('+' == c)
		pf->flags |= FT_P_PLUS;
	else if (' ' == c)
		pf->flags |= FT_P_SPACE;
	else if ('#' == c)
		pf->flags |= FT_P_HEXPREP;
	else if ('0' == c)
		pf->flags |= FT_P_ZEROPAD;
}

static void	ft_printf_parse_qualifier(char c, t_printf_syntax *pf)
{
	if (-1 == pf->qualifier)
		pf->qualifier = c;
	else if ('l' == c || 'h' == c)
		pf->qualifier ^= 0x20;
}

void		ft_printf_parse(char const **s, t_printf_syntax *pf, va_list ap)
{
	pf->flags = 0;
	pf->base = 10;
	pf->width = -1;
	pf->qualifier = -1;
	pf->precision = -1;
	while (0 != strchr("-+ #0", **s))
		ft_printf_parse_flags(*((*s)++), pf);
	while (isdigit(**s) || '*' == **s)
		ft_printf_parse_width(s, pf, ap);
	if ('.' == **s)
		ft_printf_parse_precision(s, pf, ap);
	while (0 != strchr("hljz", **s))
		ft_printf_parse_qualifier(*((*s)++), pf);
}
