/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:50:14 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char  *ft_strchr(char const *s, int c)
{
    uint8_t         d;
    LIBSTR_TYPE     k;

    if (0 == c)
        return ((char *)s + ft_strlen(s));
    d = (uint8_t)c;
    while (!ALIGNED(s, sizeof(LIBSTR_TYPE)))
    {
        if (0 == *s)
            return (0);
        if (*(uint8_t *)s == c)
            return ((char *)s);
        ++s;
    }
    k = LIBSTR_WORD(d);
    while (!DETECTNULL(*(LIBSTR_TYPE *)s) && !DETECTCHAR(*(LIBSTR_TYPE *)s, k))
        s += sizeof(LIBSTR_TYPE);
    while (0 != *s)
    {
        if (*(uint8_t *)s == d)
            return ((char *)s);
        ++s;
    }
    return (0);
}



