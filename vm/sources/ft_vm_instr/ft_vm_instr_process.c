/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:08:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 17:45:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : Presentation
//ft_printf("attached node : '%s'\n", C_PROCESS(dead_pool->champ[CHAMP_IDX].process_head.prev)->process.header.prog_name);
void           ft_vm_instr_new_process(t_dead_pool *dead_pool)
{
   t_process   *new;

   // NB: remove NULL ?
   new = NULL;
   if (!(new = ft_memalloc(sizeof(t_process))))
      EXIT_FAIL("Error : memory allocation");
   ft_memcpy((void *)&new->process, &dead_pool->champ[CHAMP_IDX], sizeof(t_champion));
   ft_list_add(&new->list,  &dead_pool->champ[CHAMP_IDX].process_head);
}

static void     ft_vm_instr_del_process(t_list *src)
{
   t_process   *ptr;
   ptr = C_PROCESS(src);
   if (!ptr)
        return ;
   ft_list_del(src);
   ft_memdel((void **)&src);
}

void            ft_vm_instr_close_process(t_dead_pool *dead_pool)
{
	t_process		*ptr;

	ptr = C_PROCESS(&dead_pool->champ[CHAMP_IDX]);
    if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
        ft_list_apply(&dead_pool->champ[CHAMP_IDX].process_head, &ft_vm_instr_del_process);
    ft_list_del(&dead_pool->champ[CHAMP_IDX].process_head);
    ft_memdel((void **)&ptr);
}
