/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:47:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:19:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "ft_string.h"
#include "ft_printf.h"


void 				ft_vm_parse_dump(t_vm *vm, char **av)
{
    while (*av)
	{
		if (!ft_strncmp("-dump", *av, 5))
		{
			if (*(*av + 5) == '=')
				ASSERT(IS_NEG((vm->option.dump = ft_atoi(*av + 6))));
			else if (*(*av + 5) == '\0')
				ASSERT(!*(av + 1) || IS_NEG((vm->option.dump = ft_atoi(*(av + 1)))));
			else
				ASSERT(0);
		}
		++av;
	}
}
