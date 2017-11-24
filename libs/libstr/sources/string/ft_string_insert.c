/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/17 15:27:20 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_insert(t_string *string, char const *str, size_t pos)
{
	size_t	len;
	char	*p;

	len = ft_strlen(str);
    if (0 != ft_string_resize(string, string->len + len))
        ft_string_del(&string);
    else
    {
    	p = string->str;
    	if (pos > string->len)
    		pos = string->len;
    	ft_memmove(p + pos + len, p + pos, string->len - pos);
    	ft_strncpy(string->str + pos, str, len);
    	string->len += len;
    	*(string->str + string->len) = 0;
    }
    return (string);
}
