/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 20:10:11 by Zoellingam       ###   ########.fr       */
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
}

void	ft_parser_del(t_parser *parser)
{
	ft_list_apply(&parser->statement_head, &ft_parser_del_statement);
}

