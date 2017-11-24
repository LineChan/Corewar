/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_ncpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/17 15:27:32 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_ncpy(t_string *string, char const *str, size_t nb)
{
	size_t	len;

	len = ft_strnlen(str, nb);
    if (0 != ft_string_resize(string, len))
        ft_string_del(&string);
    else
    {
    	ft_strncpy(string->str, str, len);
        *(string->str + len) = 0;
    	string->len = len;
    }
    return (string);
}
