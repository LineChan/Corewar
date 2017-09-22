/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:55:55 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int ft_memcmp(void const *s1, void const *s2, size_t n)
{
    char *p1;
    char *p2;

    if (s1 != s2)
    {
        p1 = (char *)s1;
        p2 = (char *)s2;
        while (n >= sizeof(LIBSTR_TYPE) && *(LIBSTR_TYPE *)p1 == *(LIBSTR_TYPE *)p2)
        {
            p1 += sizeof(LIBSTR_TYPE);
            p2 += sizeof(LIBSTR_TYPE);
            n -= sizeof(LIBSTR_TYPE);
        }
        while (0 != n--)
        {
            if (*(uint8_t *)p1 != *(uint8_t *)p2)
                return (*(uint8_t *)p1 - *(uint8_t *)p2);
            ++p1;
            ++p2;
        }
    }
    return (0);
}
