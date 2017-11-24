/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:52:40 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_strnstr(char const *s1, char const *s2, size_t n)
{
    int i;
    int j;

    if (!*s2)
        return ((char *)s1);
    i = 0;
    while (0 != *(s1 + i) && i < (int)n)
    {
        j = 0;
        while (*(s2 + j) == *(s1 + i + j) && (i + j) < (int)n)
            ++j;
        if (0 == *(s2 + j))
            return ((char *)(s1 + i));
        ++i;
    }
    return (0);
}
