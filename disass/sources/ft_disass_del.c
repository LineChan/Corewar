/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 02:09:48 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include <unistd.h>

static void	ft_disass_del_label(t_list *it)
{
	t_label	*label;

	label = C_LABEL(it);
	ft_memdel((void **)&label);
}

static void	ft_disass_del_instr(t_list *it)
{
	t_instr_node	*instr;

	instr = C_INSTR(it);
	ft_instruction_del(&instr->instr);
	ft_memdel((void **)&instr);
}

void 		ft_disass_del(t_disass *dsm)
{
	close(dsm->fd_in);
	close(dsm->fd_out);
	ft_option_del(&dsm->opt);
	ft_list_apply(&dsm->label_head, &ft_disass_del_label);
	ft_list_apply(&dsm->instr_head, &ft_disass_del_instr);
}
