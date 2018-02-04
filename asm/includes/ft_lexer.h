/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:44:37 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "ft_string.h"
# include "ft_list.h"
# include "op.h"

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

typedef enum		e_token_kind
{
	TK_ERROR    	= 0,
	TK_REGISTER 	= T_REG,
	TK_DIRECT   	= T_DIR,
	TK_INDIRECT 	= T_IND,
	TK_LABEL    	= T_LAB,
	TK_NAME,
	TK_STRING,
	TK_COMMENT,
	TK_ENDLINE,
	TK_SEPARATOR,
	TK_INSTRUCTION
}					t_token_kind;

typedef struct		s_location
{
	char const		*file;
	char const		*pc;
	int				line;
	int				pos;
}					t_location;

typedef struct		s_token
{
	t_string		*data;
	t_token_kind	kind;
	int				param_op;
	t_location		loc;
	t_list			list;
}					t_token;

# define C_TOKEN(it)	CONTAINEROF(it, t_token, list)

typedef struct		s_lexer
{
	t_location		loc;
	t_list			token_head;
	int 			error;
}					t_lexer;

typedef	t_token		*(*t_lex_rule)(t_location *);

int					ft_lexer_read_header(t_lexer *lexer, t_header *header);

t_token				*ft_lexer_read(t_lexer *lexer);

void				ft_lexer_relocate(t_location *loc, size_t count);

void				ft_lexer_init(t_lexer *lexer, char const *file_name, char const *file_content);
void				ft_lexer_del(t_lexer *lexer);

t_token 			*ft_lex_reg(t_location *loc);
t_token 			*ft_lex_dir(t_location *loc);
t_token 			*ft_lex_ind(t_location *loc);
t_token 			*ft_lex_word(t_location *loc);
t_token 			*ft_lex_label(t_location *loc);
t_token				*ft_lex_header(t_location *loc);

t_token 			*ft_token_new(char const *data, size_t len, int kind, t_location *loc);
void				ft_token_del(t_list *it);

int					ft_print_location(t_lexer *lexer);

#endif
