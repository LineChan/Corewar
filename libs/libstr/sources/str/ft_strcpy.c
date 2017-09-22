/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/23 20:34:40 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_strcpy(char *dst, char const *src)
{
    char    *s;

    s = dst;
    while (!ALIGNED(s, sizeof(LIBSTR_TYPE)))
        if (0 == (*s++ = *src++))
            return (dst);
    while (!DETECTNULL(*(LIBSTR_TYPE *)src))
    {
        *(LIBSTR_TYPE *)s = *(LIBSTR_TYPE *)src;
        s += sizeof(LIBSTR_TYPE);
        src += sizeof(LIBSTR_TYPE);
    }
    while (0 != (*s++ = *src++))
        continue ;
    return (dst);
}

