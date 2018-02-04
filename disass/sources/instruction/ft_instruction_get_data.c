/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_get_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 20:51:14 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "endian.h"
#include <assert.h>

/* ASM is assumed to be little endian */
int32_t		ft_instruction_get_data(size_t bytes, uint8_t *pc, int endian_mode)
{
	int8_t value[4];
	size_t	i;

	assert(1 == bytes || 2 == bytes || 4 == bytes);
	/* Copy each bytes up to 4 from the circular context to a linear area */
	i = 0;
	while (i < bytes)
	{
		value[i] = pc[i];
		++i;
	}
	/* Apply conversion if the endian mode is different from the
	   endianess of the compiled REDCODE */
	if (1 == bytes)
		return (value[0]);
	if (2 == bytes)
	{
		if (IS_BIG_ENDIAN == endian_mode)
			return (ft_endian_convert_int16(*(int16_t *)value));
		return (*(int16_t *)value);
	}
	if (IS_BIG_ENDIAN == endian_mode)
		return (ft_endian_convert_int32(*(int32_t *)value));
	return (*(int32_t *)value);
}
