/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_read_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:45:45 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_asm.h"
# include "ft_printf.h"
# include "ft_lexer.h"
# include "ft_ctype.h"
# include "ft_string.h"
# include "endian.h"

static int	ft_lexer_read_name(t_lexer *lexer, t_header *header)
{
	t_token	*token;

	/* Read '.name' */
	token = ft_lexer_read(lexer);
	while (0 != token && TK_ENDLINE == token->kind)
		token = ft_lexer_read(lexer);
	if (0 == token || TK_NAME != token->kind)
	{
		ft_fprintf(ft_stderr, "Header name: Missing '%s' directive\n", NAME_CMD_STRING);
		return (ft_print_location(lexer));
	}
	/* Read "string" correctly quoted */
	token = ft_lexer_read(lexer);
	if (0 == token || TK_STRING != token->kind || PROG_NAME_LENGTH < token->data->len)
	{
		ft_fprintf(ft_stderr, "Header name: error\n");
		return (ft_print_location(lexer));
	}
	ft_strcpy(header->prog_name, token->data->str);
	/* Read '\n' separator */
	token = ft_lexer_read(lexer);
	if (0 == token || TK_ENDLINE != token->kind)
	{
		ft_fprintf(ft_stderr, "Header name: Missing endline separator\n");
		return (ft_print_location(lexer));
	}
	return (1);
}

static int	ft_lexer_read_comment(t_lexer *lexer, t_header *header)
{
	t_token	*token;

	/* Read '.comment' */
	token = ft_lexer_read(lexer);
	while (0 != token && TK_ENDLINE == token->kind)
		token = ft_lexer_read(lexer);
	if (0 == token || TK_COMMENT != token->kind)
	{
		ft_fprintf(ft_stderr, "Header comment: Missing '%s' directive\n", COMMENT_CMD_STRING);
		return (ft_print_location(lexer));
	}
	/* Read "string" correctly quoted */
	token = ft_lexer_read(lexer);
	if (0 == token || TK_STRING != token->kind || COMMENT_LENGTH < token->data->len)
	{
		ft_fprintf(ft_stderr, "Header comment: error\n");
		return (ft_print_location(lexer));
	}
	ft_strcpy(header->comment, token->data->str);
	/* Read '\n' separator */
	token = ft_lexer_read(lexer);
	if (0 == token || TK_ENDLINE != token->kind)
	{
		ft_fprintf(ft_stderr, "Header comment: Missing endline separator\n");
		return (ft_print_location(lexer));
	}
	return (1);
}

int			ft_lexer_read_header(t_lexer *lexer, t_header *header)
{
	ft_memset(header, 0, sizeof(*header));
	/* Read the first line, that should be '.name "string" \n' */
	if (0 == ft_lexer_read_name(lexer, header))
		return (0);
	/* Read the second line, that sould be '.comment "string" \n' */
	if (0 == ft_lexer_read_comment(lexer, header))
		return (0);
	/* Setup the magic number */
	header->magic = ft_endian_convert_int32(COREWAR_EXEC_MAGIC);
	/* At this time, we parsed the header content, but we still
	   don't know the champion size. The header will be completed
	   at the end of the parsing. */
	return (1);
}
