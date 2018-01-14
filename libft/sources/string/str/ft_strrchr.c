/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:52:46 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_strrchr(char const *s, int c)
{
    char    *current;
    char    *prev;

    if (0 == c)
        return ((char *)s + ft_strlen(s));
    prev = 0;
    current = (char *)s;
    while (0 != (current = ft_strchr(current, c)))
        prev = current++;
    return (prev);
}
