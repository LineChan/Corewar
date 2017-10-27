/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/27 18:35:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

void				ft_vm_instr_decode(unsigned char arena[], t_champion *champ)
{
   ft_vm_instr_add(arena, champ);
   ft_list_apply(&champ->champion_head, &ft_vm_print_instr);
}
