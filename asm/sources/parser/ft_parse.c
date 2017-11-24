/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/17 20:52:21 by Zoellingam       ###   ########.fr       */
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

static int	ft_parse_loop(t_parser *parser, t_lexer *lexer)
{
	t_statement	*statement;
	t_list		label_head;
	int			address;
	int			ret;

	ret = 0;
	/* first instruction start point */
	address = 0;
	/* Init label list */
	INIT_LIST_HEAD(label_head);
	/* Init statement list */
	INIT_LIST_HEAD(parser->statement_head);
	/* A program is defined by a header and at least one instruction */
	statement = ft_parse_statement(lexer, &label_head, &address);
	if (0 == statement)
		return (ret);
	ft_list_add_tail(&statement->list, &parser->statement_head);
	/* First instruction exist, loop until we reach
	   the end of file */	
	while (0 != (statement = ft_parse_statement(lexer, &label_head, &address)))
		/* add the instruction to the list */
		ft_list_add_tail(&statement->list, &parser->statement_head);
	/* address is now our instruction block size */
	parser->header.prog_size = ft_endian_convert_uint32(address);
	ft_parse_resolve_label(lexer, parser, &label_head);
	if (0 != lexer->loc.error)
		ft_fprintf(ft_stderr, "%d error%sgenerated\n", lexer->loc.error, (1 == lexer->loc.error) ? " " : "s ");
	else
		ret = 1;
	ft_list_apply(&label_head, &ft_label_del);
	return (ret);
}

int		ft_parse(t_parser *parser, char const *file, char const *file_content)
{
	t_lexer		lexer;

	ft_lexer_init(&lexer, file, file_content);
	/* Read header, check for correctness and set magic number */
	if (0 == ft_lexer_read_header(&lexer, &parser->header))
		return (0);
	/* Parse every line as instruction.
	   Loop until end of file */
	if (0 == ft_parse_loop(parser, &lexer))
		return (0);
	return (1);
}

