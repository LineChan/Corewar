/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_st.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:55:26 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 10:59:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_display_st(t_proc const *proc)
{
		ft_printf("P %4d | st r%d %d\n",
				-proc->proc_nb,
				proc->instr->args[0].data,
				proc->instr->args[1].data);
}
