/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 08:27:33 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "ft_string.h"

void			ft_instruction_del(t_instr **ptr)
{
	if (0 != *ptr)
	{
		if (INSTR_DECODE == (*ptr)->type)
			ft_memdel((void **)&(*ptr)->args.decode);
		else
			ft_memdel((void **)&(*ptr)->args.encode);
		ft_memdel((void **)ptr);
	}
}
