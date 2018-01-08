/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_close_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:47:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 00:50:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//void			ft_vm_close_process(t_list *node)
void			ft_vm_close_process(t_vm *vm)
{
	//TODO close process
	(void)vm;
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
