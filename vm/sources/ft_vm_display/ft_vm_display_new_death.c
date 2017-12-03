/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_new_death.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 01:50:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/03 16:48:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO:Libraries
#include <libc.h>
#include "ft_printf.h"

void			ft_vm_display_new_death(t_vm *vm, t_process *proc)
{

	vm->option.death[-proc->process_nb - 1] = vm->current_cycle;
}
