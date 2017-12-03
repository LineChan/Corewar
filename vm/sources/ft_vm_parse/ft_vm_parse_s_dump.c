/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_s_dump.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:21:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/03 14:51:39 by mvillemi         ###   ########.fr       */
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
			{
				if (IS_NEG((vm->option.s_dump = ft_atoi(*av + 3))))
					EXIT_FAIL("Error : -s takes a positive integer");
			}
			else if (*(*av + 2) == '\0')
			{
				if (!*(av + 1) || IS_NEG((vm->option.s_dump = ft_atoi(*(av + 1)))))
					EXIT_FAIL("Error : -s takes a positive integer");
			}
			else
				EXIT_FAIL("Error : did you mean -s=nb ?");
		}
		++av;
	}
}
