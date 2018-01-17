/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_magic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:03:46 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 16:12:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include <unistd.h>

void			ft_header_magic(t_vm *vm, int const index)
{
	/* Check read's return */
	ASSERT(!IS_NEG(read(vm->fd[index],
						&vm->header[index].magic,
						sizeof(vm->header[index].magic))));
	/* Convert the Magic Number to big endian */
	if (IS_LITTLE_ENDIAN)
		vm->header[index].magic = ft_endian_convert_uint32(vm->header[index].magic);
	/* Check if the process' magic numer is valid */
	ASSERT(vm->header[index].magic == COREWAR_EXEC_MAGIC);
}
