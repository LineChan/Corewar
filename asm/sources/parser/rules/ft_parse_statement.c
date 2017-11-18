/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_statement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/17 20:49:00 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_asm.h"
# include "ft_printf.h"
# include "ft_parser.h"

t_statement	*ft_parse_statement(t_lexer *lexer, t_list *label_head, int *address)
{
	t_statement	*st;
	t_token		*token;

	/* loop over accepted tokens that are not part of any instruction
		-->> ENDLINE and LABEL_DEFINITION tokens. */
	while (42)
	{
		token = ft_lexer_read(lexer);
		if (0 == token)
			return (0);
		/* Skip empty lines */
		if (TK_ENDLINE == token->kind)
			continue ;
		/* Add label to list */
		if (TK_LABEL == token->kind)
		{
			if (0 == ft_parse_label(token, *address, label_head))
			{
				ft_error(&lexer->loc, token, "Label %s is already defined\n", token->data->str);
				return (0);
			}
			continue ;
		}

		/* Token is not null, it is not an Endline nor a Label.
		   Instruction is expected now */
		break ;
	}
	/* Reject token if it is not an instruction */
	if (TK_INSTRUCTION != token->kind)
	{
		ft_error(&lexer->loc, token, "Unknow instruction: '%s'\n", token->data->str);
		return (0);
	}

	/* Try to parse the instruction since we skipped useless tokens */
	st = ft_parse_instruction(lexer, token);

	/* set the instruction address */
	st->address = *address;

	/* Setup the address of the next instruction */
	*address += st->instr->instr_size;
	return (st);
}
