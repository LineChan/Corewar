/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:35:02 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 17:05:11 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include "ft_string.h"
#include "ft_ctype.h"

static const t_printf_func g_printf_func[] =
{
	{'s', &ft_printf_handle_string},
	{'c', &ft_printf_handle_char},
	{'r', &ft_printf_handle_roman},
	{'k', &ft_printf_handle_date},
	{'d', &ft_printf_handle_signed},
	{'i', &ft_printf_handle_signed},
	{'a', &ft_printf_handle_address},
	{'p', &ft_printf_handle_unsigned},
	{'x', &ft_printf_handle_unsigned},
	{'o', &ft_printf_handle_unsigned},
	{'u', &ft_printf_handle_unsigned},
	{'b', &ft_printf_handle_unsigned},
	{0, 0}
};

static int	ft_printf_engine_getbase(char c)
{
	if ('x' == c || 'p' == c)
		return (16);
	if ('o' == c)
		return (8);
	if ('b' == c)
		return (2);
	return (10);
}

static void	ft_printf_engine_init(char **p, char c, t_printf_syntax *pf, va_list a)
{
	size_t	i;

	if (ft_isupper(c))
	{
		pf->flags |= FT_P_UPPERCASE;
		c ^= 0x20;
	}
	pf->base = ft_printf_engine_getbase(c);
	if ('p' == c)
	{
		pf->flags |= FT_P_HEXPREP;
		pf->qualifier = 'l';
	}
	else if ('g' == c || 'f' == c || 'e' == c)
	{
		ft_printf_handle_float(p, c, pf, a);
		return ;
	}
	i = 0;
	while (0 != (*(g_printf_func + i)).f_handle)
	{
		if (c == (*(g_printf_func + i)).c)
		{
			(*(g_printf_func + i)).f_handle(p, pf, a);
			break ;
		}
		++i;
	}
}

void		ft_printf_engine(char *p, char const *format, va_list ap)
{
	t_printf_syntax pf;

	ft_memset((void *)&pf, 0, sizeof(t_printf_syntax));
	while (0 != *format)
	{
		if ('%' != *format)
		{
			if (0 == ft_printf_handle_color(&p, &format))
				*p++ = *format++;
			continue ;
		}
		++format;
		ft_printf_parse(&format, &pf, ap);
		if (0 != ft_strchr("pkrdiobucsxXafgeG", *format))
			ft_printf_engine_init(&p, *format++, &pf, ap);
		else if (0 != ft_strchr("KRDIOBUCSAFE", *format))
		{
			pf.qualifier = 'l';
			ft_printf_engine_init(&p, *format++ ^ 0x20, &pf, ap);
		}
		else
			*p++ = *format++;
	}
}
