/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:52:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t      ft_strnlen(char const *s, size_t n)
{
    char const *p;

    p = s;
    while (!ALIGNED(s, sizeof(LIBSTR_TYPE)) && 0 != n)
    {
        if (!*s)
            return (s - p);
        ++s;
        --n;
    }
    while (!DETECTNULL(*(LIBSTR_TYPE *)s) && n >= sizeof(LIBSTR_TYPE))
    {
        s += sizeof(LIBSTR_TYPE);
        n -= sizeof(LIBSTR_TYPE);
    }
    while (0 != *s && 0 != n--)
        ++s;
    return (s - p);
}
