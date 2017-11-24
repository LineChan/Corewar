/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:54:53 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char            *ft_strstr(char const *s1, char const *s2)
{
    size_t  len;

    len = ft_strlen(s2);
    if (0 == len)
        return ((char *)s1);
    while (0 != *s1)
    {
        if (0 == ft_strncmp(s1, s2, len))
            return ((char *)s1);
        ++s1;
    }
    return (0);
}

