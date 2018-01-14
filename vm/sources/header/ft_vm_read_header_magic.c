/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_magic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:27:02 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:34:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "endian.h"
#include "ft_printf.h"
#include <unistd.h>


void 			ft_vm_read_header_magic(t_vm *vm, int index)
{
    /* Check read's return */
	ASSERT(!IS_NEG(read(vm->fd[index],
		&vm->header[index].magic,
		sizeof(vm->header[index].magic))));
	/* Convert the Magic Number to big endian */
	if (IS_LITTLE_ENDIAN)
		vm->header[index].magic =
		ft_endian_convert_uint32(vm->header[index].magic);
	/* Check if the proces' magic number is valid */
	ASSERT(vm->header[index].magic == COREWAR_EXEC_MAGIC);
}
