/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/24 22:13:22 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endian.h"

int			ft_is_big_endian(void)
{
	uint32_t x;

	x = 1;
	return ((int)(((char *)&x)[0]));
}

uint16_t	ft_endian_convert_uint16(uint16_t val) 
{
    return (val << 8) | (val >> 8);
}

int16_t		ft_endian_convert_int16(int16_t val) 
{
    return (val << 8) | ((val >> 8) & 0xff);
}

uint32_t	ft_endian_convert_uint32(uint32_t val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return (val << 16) | (val >> 16);
}

int32_t		ft_endian_convert_int32(int32_t val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return (val << 16) | ((val >> 16) & 0xffff);
}
