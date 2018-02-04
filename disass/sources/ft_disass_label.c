/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 13:00:25 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_string.h"

/*
** Safe compare function that handle overflow
*/
static int		ft_sort_label(t_list *a, t_list *b)
{
	uint32_t	abyte;
	uint32_t	bbyte;

	abyte = C_LABEL(a)->byte_pos;
	bbyte = C_LABEL(b)->byte_pos;
	return ((abyte > bbyte) - (abyte < bbyte));
}

static t_label	*ft_create_label(t_disass *dsm, uint32_t byte_target, int create)
{
	static int	id = 0;
	t_label		*label;
	t_list		*it;

	/* Iterate over known label, and compare position */
	it = dsm->label_head.next;
	while (it != &dsm->label_head)
	{
		/* If a label exist at that position,
		   return the pointer */
		if (byte_target == C_LABEL(it)->byte_pos)
			return (C_LABEL(it));
		it = it->next;
	}
	/* We need to create a label only if there is an
	   existant instruction at that position. Labels
	   never refers to random data code */
	it = dsm->instr_head.next;
	while (0 != create && it != &dsm->instr_head)
	{
		/* Found an instruction at the desired position,
		   create a new label */
		if (byte_target == C_INSTR(it)->byte_pos)
		{
			label = ft_calloc(1, sizeof(t_label));
			label->name = id++;
			label->byte_pos = byte_target;
			ft_list_add(&label->list, &dsm->label_head);
			return (label);
		}
		it = it->next;
	}
	return (0);
}

static void		ft_label_build(t_disass *dsm)
{
	t_instr	*ist;
	t_list	*it;
	int		x;

	/* iterate over instructions */
	it = dsm->instr_head.next;
	while (it != &dsm->instr_head)
	{
		ist = C_INSTR(it)->instr;
		x = ist->op->numero;
		/* At first pass, we need to creates label from direct references.
		   That means, we iterate over instructions that uses label explicitely
		   as parameters (fork, zjmp, lfork).
		   We do not creat useless label that obufscate the code with empty data */
		if (0 != ist->args[0].data && (9 == x || 12 == x || 15 == x))
		{
			x = DISASS_JUMP(dsm->header.prog_size,
				C_INSTR(it)->byte_pos, ist->args[0].data);
			/* Look if any label exist at target position. Create
			   a new one if not. */
			C_INSTR(it)->label_ref[0] = ft_create_label(dsm, x, 1);
		}
		it = it->next;
	}
}

static void		ft_label_reach(t_disass *dsm)
{
	t_instr_node	*list;
	t_list 			*it;
	int				tmp;
	int				i;

	/* iterate over instructions */
	it = dsm->instr_head.next;
	while (it != &dsm->instr_head)
	{
		/* iterate over arguments of current instruction */
		i = 0;
		list = C_INSTR(it);
		while (i < list->instr->op->nb_args)
		{
			/* if argument type is T_REG or if a label pointer
			   already exist, we need to pass */
			if (T_REG == list->instr->args[i].type || 0 != list->label_ref[i])
			{
				++i;
				continue ;
			}
			tmp = DISASS_JUMP(dsm->header.prog_size,
				list->byte_pos, list->instr->args[i].data);
			/* Look if any label exist at target position. Do
			   not create a new one if not. */
			list->label_ref[i] = ft_create_label(dsm, tmp, 0);
			++i;
		}
		it = it->next;
	}
	/* In usage, insert sort is assumed to be faster than
	   quicksort/mergesort if there is small number of
	   items in the container. In our case, I really doubt
	   that we'll work on champions that use direct-reference
	   on a big number of label. It might be very efficient
	   ft_sort_label compare function is overflow-safe. */
	ft_list_insertsort(&dsm->label_head, &ft_sort_label);
}

void			ft_disass_label(t_disass *dsm)
{
	/* Create first label at position 0 */
	ft_create_label(dsm, 0, 1);
	/* 1st pass: creates labels from DIR_CODE */
	ft_label_build(dsm);
	/* 2nd pass: check if data refers to an existant label */
	ft_label_reach(dsm);
}
