/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_float.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 03:12:00 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/16 17:43:24 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include "ft_string.h"

static void		ft_printf_handle_float_decimal_point(char *p)
{
	int n;

	while (*p != 0)
	{
		if (*p == '.')
			return ;
		if (*p == 'e')
			break ;
		p++;
	}
	if (*p != 0)
	{
		n = ft_strnlen(p, 256);
		while (n > 0)
		{
			p[n + 1] = p[n];
			n--;
		}
		*p = '.';
	}
	else
	{
		*p++ = '.';
		*p = 0;
	}
}

static void		ft_printf_handle_float_cropzeros(char *p)
{
	char *stop;

	while (*p != 0 && *p != '.')
		p++;
	if (*p++ != 0)
	{
		while (*p != 0 && *p != 'e')
			p++;
		stop = p--;
		while (*p == '0')
			p--;
		if (*p == '.')
			p--;
		while (p != stop)
			*++p = 0;
	}
}

static char		ft_printf_handle_float_get_sign(t_printf_syntax *pf, double f)
{
	char sign;

	sign = 0;
	if (pf->flags & FT_P_SIGN)
	{
		if (f < 0.0)
		{
			sign = '-';
			pf->width--;
		}
		else if (pf->flags & FT_P_PLUS)
		{
			sign = '+';
			pf->width--;
		}
		else if (pf->flags & FT_P_SPACE)
		{
			sign = ' ';
			pf->width--;
		}
	}
	if (pf->precision < 0)
		pf->precision = 6;
	return (sign);
}

static void		ft_printf_handle_float_engine(
					char **p,
					double f,
					t_printf_syntax *pf,
					char c)
{
	char	tmp[0x100];
	char	sign;
	int		n;
	int		i;

	sign = ft_printf_handle_float_get_sign(pf, f);
	if (f < 0.0)
		f = -f;
	ft_printf_parse_float(f, tmp, c, pf);
	if ((pf->flags & FT_P_HEXPREP) && pf->precision == 0)
		ft_printf_handle_float_decimal_point(tmp);
	if (c == 'g' && !(pf->flags & FT_P_HEXPREP))
		ft_printf_handle_float_cropzeros(tmp);
	n = ft_strnlen(tmp, 256);
	pf->width -= n;
	if (!(pf->flags & (FT_P_ZEROPAD | FT_P_LEFT)))
		while (pf->width-- > 0)
			*((*p)++) = ' ';
	if (sign)
		*((*p)++) = sign;
	ft_printf_prepadd(p, 0, pf);
	i = 0;
	while (i < n)
		*((*p)++) = tmp[i++];
	ft_printf_postpadd(p, 0, pf);
}

void			ft_printf_handle_float(
					char **p,
					char c,
					t_printf_syntax *pf,
					va_list ap)
{
	pf->flags |= FT_P_SIGN;
	if (pf->flags & FT_P_LEFT)
		pf->flags &= ~FT_P_ZEROPAD;
	ft_printf_handle_float_engine(p, (double)va_arg(ap, double), pf, c);
}
