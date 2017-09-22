/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:56:04 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void    *ft_memccpy(void *dst, void const *src, int endchar, size_t n)
{
    uint8_t     *p1;
    uint8_t     *p2;
    LIBSTR_TYPE k;

    p1 = (uint8_t *)dst;
    p2 = (uint8_t *)src;
    k = LIBSTR_WORD((uint8_t)endchar);
    while (n >= sizeof(LIBSTR_TYPE) && !DETECTCHAR(*(LIBSTR_TYPE *)p2, k))
    {
        *(LIBSTR_TYPE *)p1 = *(LIBSTR_TYPE *)p2;
        p1 += sizeof(LIBSTR_TYPE);
        p2 += sizeof(LIBSTR_TYPE);
        n -= sizeof(LIBSTR_TYPE);
    }
    while (0 != n--)
        if ((*p1++ = *p2++) == (uint8_t)endchar)
            return (p1);
    return (0);
}
