/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:49:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 17:06:56 by mvillemi         ###   ########.fr       */
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

	i = (size_t)ABS(MOD((proc->instr->new_pc - proc->pc)));
	ft_printf("ADV %d (0x%04x -> 0x%04x) ", i, proc->pc, proc->instr->new_pc);
	ptr = &vm->arena[0][proc->pc];
	while (i--)
	{
		if ((ptr - vm->arena[0] == MEM_SIZE))
			ptr = (unsigned char *)vm->arena[0];
		ft_printf("%02hhx ", *ptr);
		++ptr;
	}
	write(1, "\n", 1);
}
