/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 15:57:22 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_string.h"
# include "ft_parser.h"

static void	ft_parser_del_statement(t_list *it)
{
	t_statement *st;

	st = C_STATEMENT(it);
	ft_instruction_del(&st->instr);
	ft_memdel((void **)&st);
	ft_list_del(it);
}

void		ft_parser_del(t_parser *parser)
{
	ft_lexer_del(&parser->lexer);
	ft_list_apply(&parser->statement_head, &ft_parser_del_statement);
}

