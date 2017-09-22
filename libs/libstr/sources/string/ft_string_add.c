/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:57:52 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_add(t_string *string, int c)
{
	if (0 != c)
	{
	    if (0 != ft_string_resize(string, string->len + 1))
	        ft_string_del(&string);
	    else
	    {
	        *(string->str + string->len++) = c;
	        *(string->str + string->len) = 0;
	    }
    }
    return (string);
}
