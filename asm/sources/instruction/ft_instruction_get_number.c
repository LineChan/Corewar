/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_get_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 01:06:49 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_ctype.h"

int32_t	ft_instruction_encode_get_number(char const *p)
{
    int32_t number;
    int     neg;

    neg = 0;
    if ('-' == *p)
    {
    	neg = 1;
    	++p;
    }
    else if ('+' == *p)
        ++p;
    number = 0;
    while (0 != ft_isdigit(*p))
        number = (number << 3) + (number << 1) + (*p++ - '0');
    if (1 == neg)
    	number = -number;
    return (number);
}
