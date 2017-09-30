/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 20:35:46 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_printf.h"

static void	ft_gen_label(t_disass *dsm, t_instr_node *ist)
{
	t_list	*it;

	it = dsm->label_head.next;
	while (it != &dsm->label_head)
	{
		if (C_LABEL(it)->byte_pos == ist->byte_pos)
		{
			ft_fprintf(dsm->fd_out, "\nl_%d:\n", C_LABEL(it)->name);
			break ;
		}
		it = it->next;
	}
}

static void	ft_gen_instr(t_disass *dsm, t_instr_node *ist)
{
	size_t	i;

	i = 0;
	ft_fprintf(dsm->fd_out, "\t%s\t", ist->instr->name);
	(4 > ft_strlen(ist->instr->name)) && ft_fprintf(dsm->fd_out, "\t");
	while (i < ist->instr->nb_args)
	{
		if (T_REG == ist->instr->args[i].type)
			ft_fprintf(dsm->fd_out, "r%d", ist->instr->args[i].data);
		else if (T_DIR == ist->instr->args[i].type)
		{
			ft_fprintf(dsm->fd_out, "%c", DIRECT_CHAR);
			if (0 != ist->label_ref[i])
				ft_fprintf(dsm->fd_out, "%cl_%d", LABEL_CHAR, ist->label_ref[i]->name);
			else
				ft_fprintf(dsm->fd_out, "%d", ist->instr->args[i].data);
		}
		else
			ft_fprintf(dsm->fd_out, "%d", ist->instr->args[i].data);
		if (i + 1 == ist->instr->nb_args)
			ft_fprintf(dsm->fd_out, "\n");
		else
			ft_fprintf(dsm->fd_out, ", ");
		++i;
	}
}

/*
** Print header
** For instruction in instruction_list:
** 		if label_exist:
** 			print label
** 		print instruction
** 
*/
void		ft_gen(t_disass *dsm)
{
	t_list 			*it_instr;
	t_instr_node	*ist;

	ft_fprintf(dsm->fd_out, "%s\t\t\"%s\"\n", NAME_CMD_STRING, dsm->header.prog_name);
	ft_fprintf(dsm->fd_out, "%s\t\"%s\"\n", COMMENT_CMD_STRING, dsm->header.comment);
	it_instr = dsm->instr_head.next;
	while (it_instr != &dsm->instr_head)
	{
		ist = C_INSTR(it_instr);
		ft_gen_label(dsm, ist);
		ft_gen_instr(dsm, ist);
		it_instr = it_instr->next;
	}
	ft_fprintf(dsm->fd_out, "\n; generated ;");
}
