/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_get_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:45 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 16:41:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

uint32_t	ft_instr_get_data(t_vm *vm,
								t_proc *proc,
								size_t const byte,
								int const endian_mode)
{
	uint8_t		value[4];
	size_t		i;

	/* Copy each byte up to 4 from the arena */
	i = 0;
	while (i < byte)
	{
		value[i] = vm->arena[0][MOD(proc->pc + i)];
		++i;
	}
	/* Convert is the endian mode is different from the enianess of
		the compiled REDCODE */
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
