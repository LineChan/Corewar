/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_ncat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/17 15:27:29 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_ncat(t_string *string, char const *str, size_t nb)
{
	size_t	len;

	len = ft_strnlen(str, nb);
    if (0 != ft_string_resize(string, string->len + len))
        ft_string_del(&string);
    else
    {
    	ft_strncpy(string->str + string->len, str, len);
    	string->len += len;
    }
    return (string);
}
