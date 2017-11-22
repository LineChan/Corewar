/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_champion_routine.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:17:51 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 18:25:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      			Execute a routine for each champion
*
* param arena			Memory dedicated to the Virtual Machine
* param dead_pool		t_dead_pool struct for the game
* param nb_champion		Number of alive champions in the arena
*/

/* A champion is done when all its processes are done */
void			ft_vm_arena_champion_routine(unsigned char arena[2][MEM_SIZE],
                                               t_dead_pool *dead_pool)
{
    t_list      *it;

    (void)arena;
    /* Execute the process routine for the champion */
    if (dead_pool->champ[CHAMP_IDX].next_cycle <= dead_pool->current_cycle)
        ft_vm_arena_process_routine(arena, dead_pool,
                                    &dead_pool->champ[dead_pool->idx]);
    /* Check if the champion has kids, meaning other processes created */
    /* by the fork or the lfork instructions */
    if (ft_list_is_empty(&dead_pool->i_champ->process_head))
        return ;
    /* Loop on kid processes */
    it = dead_pool->champ[dead_pool->idx].process_head.next;
    while (it != &dead_pool->champ[dead_pool->idx].process_head)
    {
        if (C_PROCESS(it)->process.next_cycle <= dead_pool->current_cycle)
            ft_vm_arena_process_routine(arena, dead_pool,
                                        &C_PROCESS(it)->process);
        it = it->next;
    }
    //ft_vm_notif_champion()
}
