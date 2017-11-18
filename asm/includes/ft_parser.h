/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/17 20:42:36 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "instruction.h"
# include "ft_lexer.h"
# include "ft_list.h"

typedef struct		s_statement
{
	t_token			*token[3];
	t_instr			*instr;
	int				address;
	t_list			list;
}					t_statement;

# define C_STATEMENT(it)	CONTAINEROF(it, t_statement, list)

typedef struct		s_parser
{
	t_header		header;
	t_list			statement_head;
}					t_parser;

void				ft_parser_del(t_parser *parser);

int 				ft_parse(t_parser *parser, char const *file_name, char const *file_content);

int					ft_parse_label(t_token *token, int address, t_list *head);

t_statement			*ft_parse_statement(t_lexer *lexer, t_list *label_head, int *address);

t_statement			*ft_parse_instruction(t_lexer *lexer, t_token *token);

int					ft_parse_resolve_label(t_lexer *lexer, t_parser *parser, t_list *label_head);

#endif
