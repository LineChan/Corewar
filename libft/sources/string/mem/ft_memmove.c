/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/30 23:23:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void    *ft_memmove(void *dst, void const *src, size_t n)
{
    uint8_t    *p1;
    uint8_t    *p2;

    p1 = (uint8_t *)dst;
    p2 = (uint8_t *)src;
    if (p2 < p1 && p1 < p2 + n)
    {
        p1 += n;
        p2 += n;
        while (n >= sizeof(LIBSTR_TYPE))
        {
            p1 -= sizeof(LIBSTR_TYPE);
            p2 -= sizeof(LIBSTR_TYPE);
            *(LIBSTR_TYPE *)p1 = *(LIBSTR_TYPE *)p2;
            n -= sizeof(LIBSTR_TYPE);
        }
        while (0 != n--)
            *(uint8_t *)--p1 = *(uint8_t *)--p2;
    }
    else
        return (ft_memcpy(dst, src, n));
    return (dst);
}

