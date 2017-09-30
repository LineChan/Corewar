/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 17:42:19 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_string.h"

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

	it = dsm->label_head.next;
	while (it != &dsm->label_head)
	{
		if (byte_target == C_LABEL(it)->byte_pos)
			return (C_LABEL(it));
		it = it->next;
	}
	it = dsm->instr_head.next;
	while (0 != create && it != &dsm->instr_head)
	{
		if (byte_target == C_INSTR(it)->byte_pos)
		{
			label = ft_memalloc(sizeof(t_label));
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

	it = dsm->instr_head.next;
	while (it != &dsm->instr_head)
	{
		ist = C_INSTR(it)->instr;
		x = ist->args[0].data;
		if (0 != x && (9 == ist->op || 12 == ist->op || 15 == ist->op))
		{
			x = DISASS_JUMP(dsm->header.prog_size, C_INSTR(it)->byte_pos, x);
			C_INSTR(it)->label_ref[0] = ft_create_label(dsm, x, 1);
		}
		it = it->next;
	}
}

static void		ft_label_reach(t_disass *dsm)
{
	t_instr_node	*list;
	t_list 			*it;
	size_t			i;
	size_t			tmp;

	it = dsm->instr_head.next;
	while (it != &dsm->instr_head)
	{
		i = 0;
		list = C_INSTR(it);
		while (i < list->instr->nb_args)
		{
			if (T_REG != list->instr->op && 0 != list->label_ref[i])
			{
				++i;
				continue ;
			}
			tmp = DISASS_JUMP(dsm->header.prog_size,
				list->byte_pos, list->instr->args[i].data);
			list->label_ref[i] = ft_create_label(dsm, tmp, 0);
			++i;
		}
		it = it->next;
	}
	ft_list_insertsort(&dsm->label_head, &ft_sort_label);
}

void			ft_label_set(t_disass *dsm)
{
	/* Create first label at position 0 */
	ft_create_label(dsm, 0, 1);

	/* 1st pass: creates labels from T_DIR */
	ft_label_build(dsm);
	
	/* 2nd pass: check if T_DIR|T_IND refers to an existent label */
	ft_label_reach(dsm);
}
