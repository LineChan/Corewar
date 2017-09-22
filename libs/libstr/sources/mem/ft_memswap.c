/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:56:57 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void    ft_memswap(void *a, void *b, size_t n)
{
    LIBSTR_TYPE *fast_a;
    LIBSTR_TYPE *fast_b;
    uint8_t     *slow_a;
    uint8_t     *slow_b;

    fast_a = (LIBSTR_TYPE *)a;
    fast_b = (LIBSTR_TYPE *)b;
    while (n >= sizeof(LIBSTR_TYPE))
    {
        ft_memswap(fast_a, fast_b, sizeof(*fast_a));
        ++fast_a;
        ++fast_b;
        n -= sizeof(LIBSTR_TYPE);
    }
    slow_a = (uint8_t *)fast_a;
    slow_b = (uint8_t *)fast_b;
    while (0 != n--)
    {
        ft_memswap(slow_a, slow_b, sizeof(*slow_a));
        ++slow_a;
        ++slow_b;
    }
}

