/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_set_int8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/31 13:48:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_arena_set_int8(t_vm *vm,
								int const pc,
								int const val,
								int const nb)
{
	vm->arena[LOOP(pc)] = val;
	vm->visual.board.color[LOOP(pc)] = nb;
}
