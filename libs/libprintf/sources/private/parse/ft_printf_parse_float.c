/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 08:06:45 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 16:16:41 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include "ft_string.h"

static void		ft_printf_parse_float2(
					double value,
					t_printf_syntax *pf,
					t_printf_parsefloat *p,
					char *c)
{
	if ('l' == pf->qualifier)
		p->capexp = 1;
	if ('g' == *c)
	{
		p->fdigits = ft_printf_float_convert(value, pf->precision, p, 1);
		p->magnitude = p->decpt - 1;
		if (p->magnitude < -4 || p->magnitude > pf->precision - 1)
		{
			*c = 'e';
			pf->precision -= 1;
		}
		else
		{
			*c = 'f';
			pf->precision -= p->decpt;
		}
	}
}

static char		*ft_printf_parse_float3(
					double val,
					char *buf,
					t_printf_syntax *pf,
					t_printf_parsefloat *p)
{
	p->fdigits = ft_printf_float_convert(val, pf->precision + 1, p, 1);
	if (0 != p->sign)
		*buf++ = '-';
	*buf++ = *p->fdigits;
	if (pf->precision > 0)
		*buf++ = '.';
	ft_strncpy(buf, p->fdigits + 1, pf->precision);
	buf += pf->precision;
	*buf++ = p->capexp ? 'E' : 'e';
	if (0 == p->decpt)
		p->exp = -(val != 0.0);
	else
		p->exp = p->decpt - 1;
	if (p->exp < 0)
	{
		*buf++ = '-';
		p->exp = -p->exp;
	}
	else
		*buf++ = '+';
	*buf++ = ((p->exp / 10) % 10) + '0';
	*buf++ = (p->exp % 10) + '0';
	buf += 2;
	return (buf);
}

static char		*ft_printf_parse_float4(
					char *buffer,
					t_printf_parsefloat *p)
{
	if (p->decpt <= 0)
	{
		*buffer++ = '0';
		*buffer++ = '.';
		p->pos = 0;
		while (p->pos++ < -p->decpt)
			*buffer++ = '0';
		while (*p->fdigits)
			*buffer++ = *p->fdigits++;
	}
	else
	{
		p->pos = 0;
		while (0 != *p->fdigits)
		{
			if (p->pos++ == p->decpt)
				*buffer++ = '.';
			*buffer++ = *p->fdigits++;
		}
	}
	return (buffer);
}

void			ft_printf_parse_float(
					double value,
					char *buffer,
					char c,
					t_printf_syntax *pf)
{
	t_printf_parsefloat p;

	ft_memset((void *)&p, 0, sizeof(p));
	ft_printf_parse_float2(value, pf, &p, &c);
	if ('e' == c)
		buffer = ft_printf_parse_float3(value, buffer, pf, &p);
	else if ('f' == c)
	{
		p.fdigits = ft_printf_float_convert(value, pf->precision, &p, 0);
		if (0 != p.sign)
			*buffer++ = '-';
		if (0 != *p.fdigits)
			buffer = ft_printf_parse_float4(buffer, &p);
		else
		{
			*buffer++ = '0';
			if (pf->precision > 0)
			{
				*buffer++ = '.';
				while (0 != pf->precision--)
					*buffer++ = '0';
			}
		}
	}
	*buffer = 0;
}
