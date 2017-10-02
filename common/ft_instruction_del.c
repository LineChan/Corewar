/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 01:06:22 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "ft_string.h"

void			ft_instruction_del(t_instr **ptr)
{
	if (0 != *ptr)
	{
		ft_memdel((void **)&(*ptr)->args.decode);
		ft_memdel((void **)ptr);
	}
}
