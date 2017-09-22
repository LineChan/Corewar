/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:54:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t   ft_strsplit_count(char const *s, int (*func)(int))
{
    char const  *tmp;
    int         w;

    w = 0;
    while (0 != *s)
    {
        while (0 != *s && 0 != func((int)*s))
            ++s;
        tmp = s;
        while (0 != *s && 0 == func((int)*s))
            ++s;
        if (tmp != s)
            ++w;
    }
    return (w + 1);
}

char            **ft_strsplit(char const *s, int (*func)(int))
{
    char        **tab;
    char const  *tmp;
    size_t      i;
    int         w;

    i = ft_strsplit_count(s, func);
    if (0 != (tab = (char **)ft_memalloc(sizeof(char *) * i)))
    {
        w = 0;
        while (0 != *s)
        {
            while (0 != *s && 0 != func((int)*s))
                ++s;
            tmp = s;
            while (0 != *s && 0 == func((int)*s))
                ++s;
            if (tmp != s)
                *(tab + w++) = ft_strndup(tmp, s - tmp);
        }
        *(tab + w) = 0;
    }
    return (tab);
}
