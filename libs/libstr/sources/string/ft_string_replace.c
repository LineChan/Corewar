/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/02 14:37:21 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_replace(t_string *s, char const *find, char const *rep)
{
    size_t  len;
    char    *pos;

    if (0 != (pos = ft_strstr(s->str, find)))
    {
        len = ft_strlen(find);
        ft_string_remove(s, pos - s->str, len);
        ft_string_insert(s, rep, pos - s->str);
    }
    return (s);
}
