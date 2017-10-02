/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/01 16:01:12 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endian.h"

/*
int			ft_is_little_endian(void)
{
	union {
		unsigned int	i;
		unsigned char	c[4];
	} e = { 0x01000000 };

	return (0[(&e)->c]);
}
*/

unsigned short	ft_endian_convert_uint16(unsigned short val) 
{
    return (val << 8) | (val >> 8);
}

signed short	ft_endian_convert_int16(signed short val) 
{
    return (val << 8) | ((val >> 8) & 0xff);
}

unsigned int	ft_endian_convert_uint32(unsigned int val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return (val << 16) | (val >> 16);
}

signed int		ft_endian_convert_int32(signed int val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return (val << 16) | ((val >> 16) & 0xffff);
}
