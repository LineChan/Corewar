/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/28 00:01:30 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENDIAN_H
# define ENDIAN_H

#include <stdint.h>

/*
 * brief    Bytes swap for unsigned short
 */
uint16_t					ft_endian_convert_uint16(uint16_t val);

/*
 * brief    Bytes swap for signed short
 */
int16_t						ft_endian_convert_int16(int16_t val);

/*
 * brief    Bytes swap for unsigned int
 */
uint32_t					ft_endian_convert_uint32(uint32_t val);

/*
 * brief    Bytes swap for signed short
 */
int32_t						ft_endian_convert_int32(int32_t val);

#endif
