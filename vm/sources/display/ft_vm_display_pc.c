/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_pc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:49:28 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 02:30:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"
#include <unistd.h>
#include "macro.h"

void			ft_vm_display_pc(t_vm *vm, t_process const *proc)
{
	size_t			i;
	unsigned char	*ptr;

	i = (size_t)ABS(MOD((proc->instr->new_pc - proc->pc)));
	ft_printf("ADV %d (0x%04x -> 0x%04x) ", i,
					proc->pc - vm->arena[0],
					proc->pc + i - vm->arena[0]);
	ptr = proc->pc;
	while (i--)
	{
		if ((ptr - vm->arena[0]) == MEM_SIZE)
			ptr = (unsigned char *)vm->arena[0];
		ft_printf("%02hhx ", *ptr);
		++ptr;
	}
	write(1, "\n", 1);
}
