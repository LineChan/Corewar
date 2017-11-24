/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/24 18:20:37 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_stpcpy(char *dst, char const *src)
{
    while (!ALIGNED(dst, sizeof(LIBSTR_TYPE)))
    {
        if (0 == (*dst = *src++))
            return (dst);
        ++dst;
    }
    while (!DETECTNULL(*(LIBSTR_TYPE *)src))
    {
        *(LIBSTR_TYPE *)dst = *(LIBSTR_TYPE *)src;
        dst += sizeof(LIBSTR_TYPE);
        src += sizeof(LIBSTR_TYPE);
    }
    while (0 != (*dst = *src++))
        ++dst;
    return (dst);
}

