/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:57:31 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** 42 norm does not allow more than 4 parameters in a function.
** Also, it does not allow more than 25 lines in a function, and
** not more thant 80 characters in each line.
*/
static void     ft_memsort(
                            char *array,
                            size_t size,
                            int (*cmp)(void const *, void const *),
                            ...
                            )
{
    void    *pivot;
    int     end;
    int     begin;
    int     left;
    int     right;

    begin = *(int *)((uint8_t *)&cmp + sizeof(int));
    end = *(int *)((uint8_t *)&cmp + (sizeof(int) << 1));
    if (end <= begin)
        return ;
    pivot = array + begin;
    left = begin + size;
    right = end;
    while (left < right)
    {
        if (cmp(array + left, pivot) <= 0)
            left += size;
        else if (cmp(array + right, pivot) > 0)
            right -= size;
        else if (left < right)
            ft_memswap(array + left, array + right, size);
    }
    ft_memswap(array + begin, array + left - size, size);
    ft_memsort(array, size, cmp, begin, left - size);
    ft_memsort(array, size, cmp, right, end);
}

void            ft_qsort(
                            void *base,
                            size_t nb,
                            size_t size,
                            int (*cmp)(void const *, void const *)
                        )
{
    ft_memsort((char *)base, size, cmp, 0, nb * size); 
}
