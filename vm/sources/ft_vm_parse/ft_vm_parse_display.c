/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:27:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/30 16:13:05 by mvillemi         ###   ########.fr       */
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
			{
				if (IS_NEG((vm->option.display = ft_atoi(*av + 9))))
					EXIT_FAIL("Error : -display takes a positive interger");
			}
			else if (*(*av + 8) == '\0')
			{
				if (!*(av + 1) ||
					IS_NEG((vm->option.display = ft_atoi(*(av + 1)))))
				{
					EXIT_FAIL("Error : -display takes a positive integer");
				}
			}
			else
				EXIT_FAIL("Error : did you mean -display=nb ?");
		}
		++av;
	}
}
