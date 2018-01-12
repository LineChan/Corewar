/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_del_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:47:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/11 20:42:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

void			ft_vm_close_process(t_list *node)
{
	t_process *ptr;

	ptr = C_PROCESS(node);
	//if (!ptr || !ptr->instr)
	if (!ptr)
		return ;
	if (ptr->instr)
		ft_memdel((void **)&ptr->instr);
	ft_list_del(node);
	ft_memdel((void **)&ptr);
}

void			ft_vm_del_list(t_vm *vm)
{
	//TODO close process
	(void)vm;
	if (ft_list_is_empty(&vm->process_head))
		return ;
	ft_list_apply(&vm->process_head, &ft_vm_close_process);
	#if 0
	if (!vm->process_head)
		return ;
		#endif
	//ft_list_del(&vm->process_head);
	#if 0
	t_process	*ptr;

	ptr = C_PROCESS(node);
	if (!ptr)
		return ;
	ft_list_del(node);
	ft_memdel((void **)&ptr);
	#endif
}
