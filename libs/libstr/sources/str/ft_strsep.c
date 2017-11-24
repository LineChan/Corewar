/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/22 08:27:00 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_strsep(char **s, char const *delim)
{
    char    *begin;
    char    *end;

    begin = *s;
    if (0 != begin)
    {
        end = begin + ft_strcspn(begin, delim);
        if (0 != *end)
        {
            *end = 0;
            *s = end + 1;
        }
        else
            *s = 0;
    }
    return (begin);
}

