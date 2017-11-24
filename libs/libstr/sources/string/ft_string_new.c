/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/31 21:26:33 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_new(size_t size)
{
    t_string    *new;
    size_t      capacity;

    capacity = FT_STRING_CAPACITY_DFT;
    while (capacity <= size)
        capacity <<= 1;
    new = (t_string *)ft_memalloc(sizeof(t_string));
    new->str = (char *)ft_memalloc(sizeof(char) * capacity);
    new->len = 0;
    new->capacity = capacity;
    return (new);
}
