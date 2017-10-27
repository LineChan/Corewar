/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_bytecode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:07:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/27 18:14:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"
# include <unistd.h>

void			ft_vm_instr_bytecode(t_champion *champ)
{
	ft_printf("champ->op : %hhx\n", champ->pc);
	++champ->pc;
	ft_printf("champ->op : %hhx\n", champ->pc);
}
