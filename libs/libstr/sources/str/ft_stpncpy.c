/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/24 18:34:51 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_stpncpy(char *dst, char const *src, size_t n)
{
    while (!ALIGNED(dst, sizeof(LIBSTR_TYPE)) && 0 != n)
    {
        if (0 == (*dst = *src++))
            return (dst);
        ++dst;
        --n;
    }
    while (!DETECTNULL(*(LIBSTR_TYPE *)src) && n >= sizeof(LIBSTR_TYPE))
    {
        *(LIBSTR_TYPE *)dst = *(LIBSTR_TYPE *)src;
        dst += sizeof(LIBSTR_TYPE);
        src += sizeof(LIBSTR_TYPE);
        n -= sizeof(LIBSTR_TYPE);
    }
    while (0 != (*dst = *src++) && n--)
        ++dst;
    return (dst);
}
