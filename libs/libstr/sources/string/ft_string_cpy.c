/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:58:16 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_cpy(t_string *string, char const *str)
{
	size_t	len;

	len = ft_strlen(str);
    if (0 != ft_string_resize(string, len))
        ft_string_del(&string);
    else
    {
    	ft_strcpy(string->str, str);
    	string->len = len;
    }
    return (string);
}
