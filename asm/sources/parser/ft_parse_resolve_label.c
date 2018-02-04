/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_resolve_label.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:38:35 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_asm.h"
# include "ft_string.h"
# include "ft_printf.h"
# include "ft_parser.h"
# include "ft_label.h"
# include "endian.h"

static int	ft_label_compare(t_list *it, void const *data_ref)
{
	return (0 == ft_strcmp(C_LABEL(it)->data->str, (char *)data_ref));
}

static int	ft_parse_resolve_lookup(t_lexer *lexer, t_statement *st, t_list *head)
{
	t_instr_encode	*arg;
	t_list			*it;
	int 			diff;
	int 			i;

	/* for each instruction's parameter */
	i = 0;
	while (i < st->instr->op->nb_args)
	{
		arg = &st->instr->args[i];
		/* If we found a T_LAB type */
		if (T_LAB & arg->type)
		{
			/* Find the reference in the label table */
			it = ft_list_find_data(head, (void const *)arg->data, &ft_label_compare);
			if (0 == it)
			{
				/* Label does not exist. Abort */
				ft_fprintf(ft_stderr, "Label %s is missing\n", arg->data);
				return (ft_print_location(lexer));
			}
			diff = C_LABEL(it)->address - (st)->address;
			/* Update the token value. It now equals the diff
			   between the label position and our current instruction position */
			if (2 == arg->size)
				*(int16_t *)arg->data = ft_endian_convert_int16((int16_t)diff);
			else
				*(int32_t *)arg->data = ft_endian_convert_int32((int32_t)diff);
		}
		++i;
	}
	return (1);
}

int			ft_parse_resolve_label(t_lexer *lexer, t_parser *parser, t_list *label_head)
{
	t_list	*it;

	/* For each statement */
	it = parser->statement_head.next;
	while (it != &parser->statement_head)
	{
		/* Search if any arguments refers to a label */
		if (0 == ft_parse_resolve_lookup(lexer, C_STATEMENT(it), label_head))
			break ;
		it = it->next;
	}
	return (0);
}

