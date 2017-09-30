/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_date.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:48:51 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/16 17:42:48 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include "ft_string.h"
#include "ft_ctype.h"
#include <time.h>

void		ft_printf_handle_date(char **p, t_printf_syntax *pf, va_list ap)
{
	char	*s;
	time_t	t;
	char	c;
	size_t	n;

	t = (time_t)va_arg(ap, time_t);
	s = ctime(&t);
	n = ft_strnlen(s, pf->precision);
	ft_printf_prepadd(p, n, pf);
	if ('l' == pf->qualifier)
	{
		while (0 != (c = *s++) && 0 != n--)
			if (!(c == '\n' || (ft_isspace(c) && ft_isspace(*s))))
				*((*p)++) = ft_toupper(c);
	}
	else
	{
		while (0 != (c = *s++) && 0 != n--)
			if (!(c == '\n' || (ft_isspace(c) && ft_isspace(*s))))
				*((*p)++) = ft_tolower(c);
	}
	ft_printf_postpadd(p, n, pf);
}
