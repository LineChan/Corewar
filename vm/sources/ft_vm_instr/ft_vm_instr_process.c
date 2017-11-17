/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:08:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 11:32:19 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : Presentation

/* Create a new process and link it at the tail of the current champion */
void           ft_vm_instr_new_process(t_dead_pool *dead_pool)
{
	t_process   *new;

	if (!(new = ft_memalloc(sizeof(t_process))))
	EXIT_FAIL("Error : memory allocation");
	ft_memcpy((void *)&new->process, &dead_pool->champ[CHAMP_IDX], sizeof(t_champion));
	ft_list_add_tail(&new->list,  &dead_pool->champ[CHAMP_IDX].process_head);
}

/* Delete a process */
static void     ft_vm_instr_del_process(t_list *src)
{
	t_process   *ptr;

	ptr = C_PROCESS(src);
	if (!ptr)
		return ;
	ft_list_del(src);
	ft_memdel((void **)&src);
}

/* Delete all fork and lfork instruction created by the champion */
void            ft_vm_instr_close_process(t_dead_pool *dead_pool)
{
	t_process		*ptr;

	ptr = C_PROCESS(&dead_pool->champ[CHAMP_IDX]);
	if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
		ft_list_apply(&dead_pool->champ[CHAMP_IDX].process_head, &ft_vm_instr_del_process);
	ft_list_del(&dead_pool->champ[CHAMP_IDX].process_head);
	ft_memdel((void **)&ptr);
}
