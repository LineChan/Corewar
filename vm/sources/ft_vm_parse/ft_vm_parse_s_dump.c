/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_s_dump.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:21:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:24:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "ft_string.h"
#include "ft_printf.h"

void				ft_vm_parse_s_dump(t_vm *vm, char **av)
{
	while (*av)
	{
		if (!ft_strncmp("-s", *av, 2))
		{
			if (*(*av + 2) == '=')
				ASSERT(IS_NEG((vm->option.s_dump = ft_atoi(*av + 3))));
			else if (*(*av + 2) == '\0')
				ASSERT(!*(av + 1) || IS_NEG((vm->option.s_dump = ft_atoi(*(av + 1)))));
			else
				ASSERT(0);
		}
		++av;
	}
}
