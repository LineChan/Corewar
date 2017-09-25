/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/24 23:51:35 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENDIAN_H
# define ENDIAN_H

#include <stdint.h>

/*
 * @brief	True if machine is big endian
 */
int							ft_is_big_endian(void);

/*
 * brief    Bytes swap unsigned short
 */
uint16_t					ft_endian_convert_uint16(uint16_t val);

#define ECu16(x)			ft_endian_convert_uint16(*(uint16_t *)(x))
#define ECu16_ASSIGN(l, x)	*(uint16_t *)(l) = ECu16(x)

/*
 * brief    Bytes swap signed short
 */
int16_t						ft_endian_convert_int16(int16_t val);

#define EC16(x)				ft_endian_convert_int16(*(int16_t *)(x))
#define EC16_ASSIGN(l, x)	*(int16_t *)(l) = ECu16(x)

/*
 * brief    Bytes swap unsigned int
 */
uint32_t					ft_endian_convert_uint32(uint32_t val);

#define ECu32(x)			ft_endian_convert_uint32(*(uint32_t *)(x))
#define ECu32_ASSIGN(l, x)	*(uint32_t *)(l) = ECu16(x)

/*
 * brief    Bytes swap signed short
 */
int32_t						ft_endian_convert_int32(int32_t val);

#define EC32(x)				ft_endian_convert_int32(*(int32_t *)(x))
#define EC32_ASSIGN(l, x)	*(int32_t *)(l) = ECu16(x)

#endif
