/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:49:24 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *p;
    size_t  len;

    len = ft_strlen(s1);
    p = ft_strcpy(ft_strnew(len + ft_strlen(s2)), s1);
    /* use strcpy instead of redundant strcat: saving time */
    p = ft_strcpy(p + len, s2);
    return (p);
}
