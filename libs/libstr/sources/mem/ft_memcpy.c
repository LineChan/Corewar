/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/23 20:33:43 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void    *ft_memcpy(void *dst, void const *src, size_t n)
{
    char *p1;
    char *p2;

    if (src != dst)
    {
        p1 = dst;
        p2 = (char *)src;
        while (n >= sizeof(LIBSTR_TYPE))
        {
            *(LIBSTR_TYPE *)p1 = *(LIBSTR_TYPE *)p2;
            p1 += sizeof(LIBSTR_TYPE);
            p2 += sizeof(LIBSTR_TYPE);
            n -= sizeof(LIBSTR_TYPE);
        }
        while (n-- > 0)
            *(uint8_t *)p1++ = *(uint8_t *)p2++;
    }
    return (dst);
}

