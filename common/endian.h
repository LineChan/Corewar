/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/01 15:59:39 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENDIAN_H
# define ENDIAN_H

/*
 * brief	True if arch is big endian
 */
# define IS_BIG_ENDIAN		(*(unsigned short *)"\0\xff" < 0x100)

/*
 * brief	True is arch is little endian
 */
# define IS_LITTLE_ENDIAN	!IS_BIG_ENDIAN

/*
 * brief    Bytes swap for unsigned short
 */
unsigned short				ft_endian_convert_uint16(unsigned short val);

/*
 * brief    Bytes swap for signed short
 */
signed short				ft_endian_convert_int16(signed short val);

/*
 * brief    Bytes swap for unsigned int
 */
unsigned int				ft_endian_convert_uint32(unsigned int val);

/*
 * brief    Bytes swap for signed short
 */
signed int					ft_endian_convert_int32(signed int val);

#endif
