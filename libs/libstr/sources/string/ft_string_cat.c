/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:57:56 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_cat(t_string *string, char const *str)
{
	size_t	len;

	len = ft_strlen(str);
    if (0 != ft_string_resize(string, string->len + len))
        ft_string_del(&string);
    else
    {
    	ft_strcpy(string->str + string->len, str);
    	string->len += len;
    }
    return (string);
}
