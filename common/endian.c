/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 23:41:57 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endian.h"

void        ft_endian_apply_conversion(void *buf, uint32_t data, size_t n)
{
    if (1 == n)
        *(uint8_t *)buf = (uint8_t)data;
    else if (2 == n)
        *(uint16_t *)buf = ft_endian_convert_uint16((uint16_t)data);
    else if (4 == n)
        *(uint32_t *)buf = ft_endian_convert_uint32(data);
}

uint16_t	ft_endian_convert_uint16(uint16_t val) 
{
    return ((val << 8) | (val >> 8));
}

int16_t	    ft_endian_convert_int16(int16_t val) 
{
    return ((val << 8) | ((val >> 8) & 0xff));
}

uint32_t	ft_endian_convert_uint32(uint32_t val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return ((val << 16) | (val >> 16));
}

int32_t		ft_endian_convert_int32(int32_t val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return ((val << 16) | ((val >> 16) & 0xffff));
}
