/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:09:05 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/07 00:08:27 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs
#include "ft_printf.h"
void			ft_vm_instr_st_data(t_vm *vm,
									void *dst,
									void const *src,
									int size)
{

	while (size--)
	{
		if (!(((unsigned char *)dst - vm->arena[0]) % MEM_SIZE))
		{
			dst = vm->arena[0];
		}
		if (!(((unsigned char *)src - vm->arena[0]) % MEM_SIZE))
		{
			src = vm->arena[0];
		}
		*(char *)dst++ = *(char*)src++;
	}
}
