/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:39:37 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

typedef union		s_pf_float
{
	double			f;
	struct
	{
		uint64_t	fraction:	52;
	  	uint32_t 	exponent:	11;
		uint32_t 	negative:	1;
	};
}					t_pf_float;

/* Fast pow */
static double	ft_pf_pow(uint32_t base, uint32_t e)
{
	uint64_t	ret;

    ret = 1;
    while (0 != e)
    {
        if (e & 1)
            ret *= base;
        e >>= 1;
        base *= base;
    }
    return ((long double)ret);
}

static t_pf_buf	*ft_pf_buffer(t_pf_buf *p, t_printf *pf)
{
	long double	val;
	uint64_t	high;
	uint64_t	low;
	size_t		precision_low;
	double		round_pow;

	precision_low = (0 > pf->precision) ? 6 : pf->precision;
	high = pf->arg.d;
	val = pf->arg.d - high;
	round_pow = val * ft_pf_pow(10, precision_low);
	low = (uint64_t)(round_pow + (round_pow != (uint64_t)round_pow));

	// Print high value:
	pf->arg.i = pf->arg.d;
	pf->specifier = 'd';
	ft_pf_handle_d(p, pf);

	if (0 != precision_low)
	{
		ft_pf_buffer_add(p, '.');
		pf->arg.i = low;
		pf->flags = 0;
		ft_pf_handle_d(p, pf);
	}
	return (0);
}

void	ft_pf_handle_f(t_pf_buf *p, t_printf *pf)
{
	t_pf_buf	*buffer;
	t_pf_buf	*prefix;

	if (0 > pf->arg.d)
	{
		pf->flags |= PF_FLAG_SIGNED;
		pf->arg.d = -pf->arg.d;
	}
	buffer = ft_pf_buffer(p, pf);
	return ;
//	prefix = ft_pf_prefix(pf);
	(void)p;
	(void)prefix;
}
