/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:59:37 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** Do not use ft_strnew cause of capacity
*/
int     ft_string_resize(t_string *ptr, size_t size)
{
    size_t      capacity;
    char        *save;

    if (size < ptr->len)
    {
        ptr->len = size;
        *(ptr->str + size) = 0;
    }
    else
    {
        capacity = ptr->capacity;
        while (capacity <= size)
            capacity <<= 1;
        save = ptr->str;
        if (0 == (ptr->str = (char *)ft_memalloc(sizeof(char) * capacity)))
            return (-1);
        ft_strcpy(ptr->str, save);
        ptr->capacity = capacity;
        ft_strdel(&save);
    }
    return (0);
}
