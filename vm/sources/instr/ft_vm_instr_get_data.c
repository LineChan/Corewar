/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_get_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:18:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/08 21:48:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

#if 0
int32_t			ft_instruction_get_data(size_t byte,
									uint8_t *pc,
									t_vm *vm,
									int const endian_mode)
{
	uint8_t			value[4];
	size_t			i;

	/* Copy each byte up to 4 from the circular contect to a linear area */
	i = 0;
	tmp = 0;
	while (i < size)
	{
		value[i] = vm->arena[0][LOOP(pc + i - vm->arena[0])];
		++i;
	}
	/* Apply conversion if the endian mode is different from the endianess */
	/* of the compiled REDCODE */
	if (1 == byte)
		return (*(int8_t *)value);
	if (2 == byte)
	{
		if (IS_BIG_ENDIAN == endian_mode)
			return (ft_endian_convert_int16(*(int16_t *)value));
		return (*(int16_t *)value);
	}
	if (IS_BIG_ENDIAN == endian_mode)
		return (ft_endian_convert_int32(*(int32_t *)value));
	return (*(int32_t *)value);
}
#endif
#if 0
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
#endif
