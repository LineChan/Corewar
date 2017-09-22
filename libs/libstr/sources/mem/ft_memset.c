/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:56:41 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void    *ft_memset(void *p, int c, size_t n)
{
    uint8_t     *m;
    uint8_t     k;
    LIBSTR_TYPE kw;

    m = (uint8_t *)p;
    k = (uint8_t)c;
    kw = LIBSTR_WORD(k);
    while (!ALIGNED(m, sizeof(uint8_t)) && n)
    {
        *m++ = k;
        --n;
    }
    while (n >= sizeof(LIBSTR_TYPE))
    {
        *(LIBSTR_TYPE *)m = kw;
        m += sizeof(LIBSTR_TYPE);
        n -= sizeof(LIBSTR_TYPE);
    }
    while (0 != n--)
        *m++ = k;
    return (p);
}

