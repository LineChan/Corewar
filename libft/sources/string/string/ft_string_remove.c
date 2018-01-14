/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/02 14:38:25 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_remove(t_string *string, size_t pos, size_t nb)
{
    char    *p;

    if (0 != nb && pos < string->len)
    {
        p = string->str;
        if (pos + nb > string->len)
            nb = string->len - pos;
        ft_memmove(p + pos, p + pos + nb, string->len - (pos + nb));
        string->len -= nb;
        *(string->str + string->len) = 0;
    }
    return (string);
}
