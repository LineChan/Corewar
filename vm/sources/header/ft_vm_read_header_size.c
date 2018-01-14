/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:48:11 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:36:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "endian.h"
#include "ft_printf.h"
#include <unistd.h>

void 			ft_vm_read_header_size(t_vm *vm, int index)
{
    /* Check read's return and align bits if necessary */
	ASSERT(!IS_NEG(read(vm->fd[index], &vm->header[index].prog_size,
		sizeof(vm->header[index].prog_size))));
	/* Convert the process' size to big endian */
	if (IS_LITTLE_ENDIAN)
		vm->header[index].prog_size =
		ft_endian_convert_uint32(vm->header[index].prog_size);
	/* Check if the process' magic number is valid */
	ASSERT(vm->header[index].prog_size <= CHAMP_MAX_SIZE);
}
