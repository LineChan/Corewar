/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:47:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/24 13:51:11 by mvillemi         ###   ########.fr       */
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
			{
				if (IS_NEG((vm->option.dump = ft_atoi(*av + 6))))
					EXIT_FAIL("Error : -dump takes a positive integer");
			}
			else if (*(*av + 5) == '\0')
			{
				if (!*(av + 1) || IS_NEG((vm->option.dump = ft_atoi(*(av + 1)))))
					EXIT_FAIL("Error : -dump takes a positive integer");
			}
			else
				EXIT_FAIL("Error : did you mean -dump=nb ?");
		}
		++av;
	}
}
