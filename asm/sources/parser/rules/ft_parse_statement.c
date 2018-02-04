/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_statement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:47:15 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_asm.h"
# include "ft_printf.h"
# include "ft_parser.h"
# include "ft_lexer.h"

t_statement	*ft_parse_statement(t_lexer *lexer, t_list *label_head, int *address)
{
	t_statement	*st;
	t_token		*token;

	/* We can match any '\n' or any label definition before matching an instruction
	   We need to loop over accepted tokens that are not part of any instruction
		-->> ENDLINE and LABEL_DEFINITION tokens. */
	while (42)
	{
		/* Ask the lexer to read a token */
		token = ft_lexer_read(lexer);
		/* return null if there is no token anymore */
		if (0 == token)
			return (0);
		/* The token is already added in a 'token list' by the lexer. We do
		   not care about any memory usage at this time. Everything will be
		   correctly deleted in another time. */

		/* Ask for another token if we match a '\n' */
		if (TK_ENDLINE == token->kind)
			continue ;
		/* If we matched a label definition token, we first add it
		   to the label table before asking the lexer for another token */
		if (TK_LABEL == token->kind)
		{
			/* Check if label is already defined */
			if (0 == ft_parse_label(token, *address, label_head))
			{
				ft_fprintf(ft_stderr, "Label %s is already defined\n", token->data->str);
				ft_print_location(lexer);
				return (0);
			}
			/* Ask for a new token */
			continue ;
		}
		/* Token is not null, it is not an Endline nor a Label.
		   Instruction is expected now */
		break ;
	}
	/* Reject token if it is not an instruction */
	if (TK_INSTRUCTION != token->kind)
	{
		ft_fprintf(ft_stderr, "Unknow instruction %s\n", token->data->str);
		ft_print_location(lexer);
		return (0);
	}
	/* Try to parse the instruction since we skipped useless tokens */
	st = ft_parse_instruction(lexer, token);
	if (0 != st)
	{
		/* set the instruction address */
		st->address = *address;
		/* Setup the address of the next instruction */
		*address += st->instr->instr_size;
	}
	return (st);
}
