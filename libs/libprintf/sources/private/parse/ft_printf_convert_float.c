/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 19:32:33 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 15:32:55 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

# define CLAMP(x, y, z)	(((y) < (x)) ? (x) : ((y) > (z)) ? (z) : (y))

static void		ft_printf_float_set_mantis(t_printf_float *f, int mask)
{
	uint32_t mant;

	if (mask < 32)
	{
		mant = f->low & ~((1 << mask) - 1);
		f->low = mant;
	}
	else
	{
		f->low = 0;
		mask -= 32;
		mant = (f->high & 0xfffff) & ~((1 << mask) - 1);
		f->high = (f->high & ~(0xfffff)) | (mant & 0xfffff);
	}
}

static double	ft_printf_float_modf(double value, double *iptr)
{
	t_printf_float	*f;
	double	tmp;
	int		exp;
	int		mask_bits;

	f = (t_printf_float *)&value;
	exp = ((f->high >> 0x14) & 0x7ff) - 0x3ff;
	if (exp < 0)
	{
		*iptr = 0;
		return (value);
	}
	mask_bits = 52 - exp;
	if (0 >= mask_bits)
	{
		*iptr = value;
		return (0);
	}
	tmp = value;
	ft_printf_float_set_mantis(f, mask_bits);
	*iptr = value;
	return (tmp - value);
}

static char		*ft_printf_float_convert_3(t_printf_parsefloat *pf, int eflag)
{
	if (pf->p1 >= (pf->cvtbuf + 80))
	{
		*(pf->cvtbuf + 79) = 0;
		return (pf->cvtbuf);
	}
	pf->p2 = pf->p1;
	*pf->p1 += 5;
	while (*pf->p1 > '9')
	{
		*pf->p1 = '0';
		if (pf->p1 > pf->cvtbuf)
			++*--pf->p1;
		else
		{
			*pf->p1 = '1';
			(pf->decpt)++;
			if (0 == eflag && (pf->p2++ > pf->cvtbuf))
				*(pf->p2 - 1) = '0';
		}
	}
	*pf->p2 = 0;
	return (pf->cvtbuf);
}

static void		ft_printf_float_convert_2(t_printf_parsefloat *pf, double *arg)
{
	*arg = ft_printf_float_modf(*arg, &pf->t2);
	pf->p1 = pf->cvtbuf + 80;
	if (0 != pf->t2)
	{
		pf->p1 = pf->cvtbuf + 80;
		while (0 != pf->t2)
		{
			pf->t1 = ft_printf_float_modf(pf->t2 / 10, &pf->t2);
			*--pf->p1 = (int)((pf->t1 + 0.03) * 10) + '0';
			++pf->count;
		}
		while (pf->p1 < (pf->cvtbuf + 80))
			*pf->p2++ = *pf->p1++;
	}
	else if (*arg > 0)
	{
		while ((pf->t1 = *arg * 10) < 1)
		{
			*arg = pf->t1;
			--pf->count;
		}
	}
}

char			*ft_printf_float_convert(double arg, int ndigits, t_printf_parsefloat *pf, int eflag)
{
	ndigits = CLAMP(0, ndigits, 78);
	pf->count = 0;
	pf->sign = 0;
	pf->p2 = pf->cvtbuf;
	if (arg < 0)
	{
		pf->sign = 1;
		arg = -arg;
	}
	ft_printf_float_convert_2(pf, &arg);
	pf->p1 = pf->cvtbuf + ndigits;
	if (0 == eflag)
		pf->p1 += pf->count;
	pf->decpt = pf->count;
	if (pf->p1 < pf->cvtbuf)
	{
		*pf->cvtbuf = 0;
		return (pf->cvtbuf);
	}
	while (pf->p2 <= pf->p1 && pf->p2 < (pf->cvtbuf + 80))
	{
		arg = ft_printf_float_modf(arg * 10, &pf->t1);
		*pf->p2++ = (int)pf->t1 + '0';
	}
	return (ft_printf_float_convert_3(pf, eflag));
}
