/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_get_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:45 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 15:45:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

int32_t		ft_instr_get_data(size_t bytes,
									uint8_t *context,
									int	endian_mode)
{
	uint8_t value[4];
	size_t	i;

	/* Copy each bytes up to 4 from the circular context to a linear area */
	i = 0;
	while (i < bytes)
	{
		value[i] = *(context + i);
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
