/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:16:51 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/24 14:16:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void 				ft_vm_parse(t_vm *vm, char **av)
{
	ft_vm_parse_log(vm, av);
	ft_vm_parse_start_c(vm, av);
	ft_vm_parse_dump(vm, av);
	ft_vm_parse_champion(vm, av);
}
