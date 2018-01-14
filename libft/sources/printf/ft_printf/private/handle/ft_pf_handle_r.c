/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:40:14 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static const char   *g_pf_roman[3][10] =
{
    { "I", "II", "III", "VI", "V", "IV", "IIV", "IIIV", "XI" },
    { "X", "XX", "XXX", "LX", "L", "XL", "XXL", "XXXL", "CX" },
    { "C", "CC", "CCC", "DC", "D", "CD", "CCD", "CCCD", "MC" }
};

static char         *ft_pf_roman(uint16_t nb_low, uint16_t nb_high, int const lower)
{
    static char buf[0x30];
    char const  *tmp;
    char        *p;
    size_t      it;

    it = 0;
    p = buf + 0x30;
    while (0 != nb_low)
    {
        if (nb_low % 10)
        {
            tmp =g_pf_roman[it][(nb_low % 10) - 1];
            while (0 != *tmp)
                *--p = *tmp++ | lower;
        }
        ++it;
        nb_low /= 10;
    }
    while (0 != nb_high--)
        *--p = 'M' | lower;
    return (p);
}

void                ft_pf_handle_r(t_pf_buf *p, t_printf *pf)
{
    if (0 == pf->arg.i)
        pf->arg.p = "0";
    else
        pf->arg.p = ft_pf_roman(pf->arg.i % 1000, pf->arg.i / 1000, pf->specifier & 32);
    pf->specifier = 's';
    ft_pf_handle_s(p, pf);
}
