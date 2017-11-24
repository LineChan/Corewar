/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/19 20:37:47 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_strncpy(char *dst, char const *src, size_t n)
{
    size_t  len;

    len = ft_strnlen(src, n);
    ft_memcpy(dst, src, len);
    dst += len;
    if (len == n)
        return (dst);
    return (ft_memset(dst, 0, n - len));

}
