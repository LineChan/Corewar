/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_start_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:33:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/25 23:32:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_string.h"
#include "macro.h"
#include "ft_printf.h"

void 			ft_vm_parse_start_c(t_vm *vm, char **av)
{
	while (*av)
	{
		if (!ft_strncmp("-start_c", *av, 8))
		{
			if (*(*av + 8) == '=')
			{
				if (IS_NEG((vm->current_cycle = ft_atoi(*av + 9))))
					EXIT_FAIL("Error : -start_c takes a positive integer");
			}
			else if (*(*av + 8) == '\0')
			{
				if (!*(*av + 1) ||
						IS_NEG((vm->current_cycle = ft_atoi(*(av + 1)))))
					EXIT_FAIL("Error : -start_c takes a positive integer");
			}
			else
				EXIT_FAIL("Error : did you mean -start_c=nb?");
		}
		++av;
	}
}
