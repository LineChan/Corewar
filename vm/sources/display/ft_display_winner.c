/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_winner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:26:31 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 17:41:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_display_winner(t_vm *vm)
{
	(void)vm;
	/* Print the output of the game */
	if (DISPLAY_32)
		ft_visual_end(&vm->visual);
	else
	{
		ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive,
			vm->header[vm->last_alive - 1].prog_name);
	}
}
