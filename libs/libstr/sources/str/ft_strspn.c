/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:54:50 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t  ft_strspn(char const *s, char const *accept)
{
    char const  *spanp;
    char const  *p;
    char        sc;
    char        c;
    int         keep;

    p = s;
    keep = 1;
    while (0 != keep)
    {
        keep = 0;
        c = *p++;
        spanp = accept;
        while (0 == keep && 0 != (sc = *spanp++))
            if (sc == c)
                keep = 1;
    }
    return (p - 1 - s);
}
