/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrstruction_del.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/12/11 22:11:58 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_string.h"

void	ft_instruction_del(t_instr **ptr)
{
	ft_memdel((void **)ptr);
}
