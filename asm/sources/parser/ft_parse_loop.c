/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:38:39 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_label.h"
# include "ft_string.h"
# include "ft_printf.h"
# include "ft_parser.h"
# include "endian.h"

static void	ft_label_del(t_list *it)
{
	t_label *ptr;

	ptr = C_LABEL(it);
	ft_memdel((void **)&ptr);
}

void		ft_parse_loop(t_parser *parser, t_lexer *lexer)
{
	t_statement	*statement;
	t_list		label_head;
	int			address;
	int			ret;

	ret = 0;
	/* first instruction start point */
	address = 0;
	/* Init label list. It is used as simple table where
	 * I store 2 informations: name and address of the declaration */
	INIT_LIST_HEAD(label_head);
	/* Init statement list */
	INIT_LIST_HEAD(parser->statement_head);
	/* A program is defined by a header and at least one instruction */
	statement = ft_parse_statement(lexer, &label_head, &address);
	if (0 == statement)
		return ;
	ft_list_add_tail(&statement->list, &parser->statement_head);
	/* We parsed an instruction. The champion can now have any instruction he want */
	while (0 != (statement = ft_parse_statement(lexer, &label_head, &address)))
		/* add the instruction to the list */
		ft_list_add_tail(&statement->list, &parser->statement_head);
	/* address is now our instruction block size, we can fill the header */
	parser->header.prog_size = ft_endian_convert_uint32(address);
	/* For each statement, we need to check if any arguments refers to
		a label (We setted the 'T_LAB' for label arguments).
		When resolved, we can cleanup our label table. */
	ft_parse_resolve_label(lexer, parser, &label_head);
	ft_list_apply(&label_head, &ft_label_del);
}
