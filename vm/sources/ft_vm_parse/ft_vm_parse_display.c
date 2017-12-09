/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:27:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:12:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "macro.h"
#include "ft_printf.h"

void			ft_vm_parse_display(t_vm *vm, char **av)
{
	while (*av)
	{
		if (!ft_strncmp("-display", *av, 8))
		{
			if (*(*av + 8) == '=')
				ASSERT(IS_NEG((vm->option.display = ft_atoi(*av + 9))));
			else if (*(*av + 8) == '\0')
			{
				ASSERT(!*(av + 1) ||
					IS_NEG((vm->option.display = ft_atoi(*(av + 1)))));
			}
			else
				ASSERT(0);
		}
		++av;
	}
}
