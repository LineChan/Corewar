/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_st_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:37:46 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 10:53:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_instr_st_data(size_t bytes, void *dst, void *src, t_vm *vm)
{
	while (bytes--)
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
