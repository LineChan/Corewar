/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_st.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:09:17 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:24:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_display_st(t_process const *proc)
{
	ft_printf("P %4d | st r%d %d\n",
			-proc->process_nb,
			proc->instr->args[0].data,
			proc->instr->args[1].data);
	}
