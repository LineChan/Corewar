/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:49:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/28 20:04:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"
#include <unistd.h>

void		ft_display_pc(t_vm *vm, t_proc const *proc)
{
	size_t			i;
	unsigned char	*ptr;

	i = proc->instr->size;
	ft_printf("ADV %d (0x%04x -> 0x%04x) ", i, proc->pc, proc->pc + i);
	ptr = &vm->arena[proc->pc];
	while (i--)
	{
		if ((ptr - vm->arena == MEM_SIZE))
			ptr = (unsigned char *)vm->arena;
		ft_printf("%02hhx ", *ptr);
		++ptr;
	}
	write(1, "\n", 1);
}
