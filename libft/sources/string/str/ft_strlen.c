/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:49:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t      ft_strlen(char const *s)
{
    char const *p;

    p = s;
    while (!ALIGNED(s, sizeof(LIBSTR_TYPE)))
    {
        if (0 == *s)
            return (s - p);
        ++s;
    }
    while (!DETECTNULL(*(LIBSTR_TYPE *)s))
        s += sizeof(LIBSTR_TYPE);
    while (0 != *s)
        ++s;
    return (s - p);
}
