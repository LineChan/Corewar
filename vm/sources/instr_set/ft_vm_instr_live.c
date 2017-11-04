/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:25:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/04 17:14:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

#include <libc.h>
void           ft_vm_instr_live(unsigned char arena[],
                                t_dead_pool *dead_pool,
                                t_champion *champ)
{
    int             number;

    (void)arena;
    number = ft_instruction_get_data(4, champ->pc + 1);
    if (number == 1)
        ++dead_pool->champion1.live;
    else if (number == 2)
        ++dead_pool->champion2.live;
    else if (number == 3)
        ++dead_pool->champion3.live;
    else if (number == 4)
        ++dead_pool->champion4.live;
    if (DEBUG_MODE)
    {
        ft_printf("live [1] : %d\n", dead_pool->champion1.live);
        ft_printf("live [2] : %d\n", dead_pool->champion2.live);
        ft_printf("live [3] : %d\n", dead_pool->champion3.live);
        ft_printf("live [4] : %d\n", dead_pool->champion4.live);
        getchar();
    }
    champ->pc += 5;
}
