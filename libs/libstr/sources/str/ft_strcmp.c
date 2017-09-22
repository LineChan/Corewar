/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/23 20:34:36 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int     ft_strcmp(char const *s1, char const *s2)
{
    while (*(LIBSTR_TYPE *)s1 == *(LIBSTR_TYPE *)s2)
    {
        if (DETECTNULL(*(LIBSTR_TYPE *)s1))
            return (0);
        s1 += sizeof(LIBSTR_TYPE);
        s2 += sizeof(LIBSTR_TYPE);
    }
    while (*s1 && *(uint8_t *)s1 == *(uint8_t *)s2)
    {
        ++s1;
        ++s2;
    }
    return (*(uint8_t *)s1 - *(uint8_t *)s2);
}

