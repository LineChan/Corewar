/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass_gen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 15:10:21 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_printf.h"
#include "ft_string.h"

static void	ft_disass_gen_label(t_disass *dsm, t_instr_node *ist)
{
	t_list	*it;

	/* Iterate over label */
	it = dsm->label_head.next;
	while (it != &dsm->label_head)
	{
		/* Found label at the current instruction position */
		if (C_LABEL(it)->byte_pos == ist->byte_pos)
		{
			ft_fprintf(dsm->fd_out, "\nl_%d:\n", C_LABEL(it)->name);
			break ;
		}
		it = it->next;
	}
}

static void	ft_disass_gen_instr(t_disass *dsm, t_instr_node *ist)
{
	int	i;

	/* Print instruction name */
	i = 0;
	ft_fprintf(dsm->fd_out, "\t%s\t", ist->instr->op->name);
	(4 > ft_strlen(ist->instr->op->name)) && ft_fprintf(dsm->fd_out, "\t");
	/* Iterate over arguments */
	while (i < ist->instr->op->nb_args)
	{
		/* Print register: r%d */
		if (T_REG == ist->instr->args[i].type)
			ft_fprintf(dsm->fd_out, "r%d", ist->instr->args[i].data);
		/* Print direct: %<label> or %<value> */
		else if (T_DIR == ist->instr->args[i].type)
		{
			ft_fprintf(dsm->fd_out, "%c", DIRECT_CHAR);
			if (0 != ist->label_ref[i])
				ft_fprintf(dsm->fd_out, "%cl_%d", LABEL_CHAR, ist->label_ref[i]->name);
			else
				ft_fprintf(dsm->fd_out, "%d", ist->instr->args[i].data);
		}
		/* Print indirect: <value> */
		else
			ft_fprintf(dsm->fd_out, "%d", ist->instr->args[i].data);
		/* Handle coma/endline */
		if (i + 1 == ist->instr->op->nb_args)
			ft_fprintf(dsm->fd_out, "\n");
		else
			ft_fprintf(dsm->fd_out, ", ");
		++i;
	}
}

void		ft_disass_gen(t_disass *dsm)
{
	t_list 			*it_instr;
	t_instr_node	*ist;

	/* Print header */
	ft_fprintf(dsm->fd_out, "%s\t\t\"%s\"\n", NAME_CMD_STRING, dsm->header.prog_name);
	ft_fprintf(dsm->fd_out, "%s\t\"%s\"\n", COMMENT_CMD_STRING, dsm->header.comment);
	/* Iterate over instructions */
	it_instr = dsm->instr_head.next;
	while (it_instr != &dsm->instr_head)
	{
		ist = C_INSTR(it_instr);
		/* Check if a label exist at the instruction position */
		ft_disass_gen_label(dsm, ist);
		/* Print the current instruction */
		ft_disass_gen_instr(dsm, ist);
		it_instr = it_instr->next;
	}
	/* Signature */
	ft_fprintf(dsm->fd_out, "\n; generated ;\n");
}
