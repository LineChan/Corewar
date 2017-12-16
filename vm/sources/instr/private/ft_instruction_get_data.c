/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_get_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2017/12/15 14:49:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction_parse.h"
#include "endian.h"

/* ASM is assumed to be little endian */
int32_t		ft_instruction_get_data(size_t bytes,
									uint8_t *pc,
									uint8_t *context,
									int	endian_mode)
{
	uint8_t value[4];
	size_t	i;

	/* Copy each bytes up to 4 from the circular context to a linear area */
	i = 0;
	while (i < bytes)
	{
		value[i] = context[LOOP(pc + i - context)];
		++i;
	}
	/* Apply conversion if the endian mode is different from the
	   endianess of the compiled REDCODE */
	if (1 == bytes)
		return (*(int8_t *)value);
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
