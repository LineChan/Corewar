/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_set_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2017/12/15 14:50:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction_parse.h"
#include "endian.h"

/* ASM is assumed to be little endian */
void	ft_instruction_set_data(size_t bytes,
								uint8_t *pc,
								uint8_t *context,
								uint8_t *arena)
{
	while (0 != bytes--)
		context[LOOP(context + bytes - arena)] = pc[LOOP(pc + bytes - arena)];
}
