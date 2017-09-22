/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:55:59 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void    *ft_memchr(void const *m, int c, size_t n)
{
    char        *p;
    uint8_t     d;
    LIBSTR_TYPE k;

    p = (char *)m;
    d = (uint8_t)c;
    while (!ALIGNED(p, sizeof(LIBSTR_TYPE)) && 0 != n)
    {
        if (*(uint8_t *)p == d)
            return ((void *)p);
        ++p;
        --n;
    }
    k = LIBSTR_WORD(d);
    while ((!DETECTCHAR(*(LIBSTR_TYPE *)p, k)) && n > sizeof(LIBSTR_TYPE))
    {
        p += sizeof(LIBSTR_TYPE);
        n -= sizeof(LIBSTR_TYPE);
    }
    while (0 != n--)
        if (*(uint8_t *)p++ == d)
            return ((void *)(p - 1));
    return (0);
}
