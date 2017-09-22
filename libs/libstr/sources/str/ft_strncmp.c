/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:51:49 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int ft_strncmp(char const *s1, char const *s2, size_t n)
{
    if (!n)
        return (0);
    while (n >= sizeof(LIBSTR_TYPE) && *(LIBSTR_TYPE *)s1 == *(LIBSTR_TYPE *)s2)
    {
        n -= sizeof(LIBSTR_TYPE);
        if (0 == n || DETECTNULL(*(LIBSTR_TYPE *)s1))
            return (0);
        s1 += sizeof(LIBSTR_TYPE);
        s2 += sizeof(LIBSTR_TYPE);
    }
    while (0 != n-- && *(uint8_t *)s1 == *(uint8_t *)s2)
    {
        if (0 == n || !*s1)
            return (0);
        ++s1;
        ++s2;
    }
    return (*(uint8_t *)s1 - *(uint8_t *)s2);
}

