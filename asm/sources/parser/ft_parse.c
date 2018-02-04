/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:38:41 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_label.h"
# include "ft_string.h"
# include "ft_printf.h"
# include "ft_parser.h"
# include "endian.h"

int		ft_parse(t_parser *parser, char const *file, char const *file_content)
{
	ft_lexer_init(&parser->lexer, file, file_content);
	/* Read header, check for correctness and set magic number */
	if (0 == ft_lexer_read_header(&parser->lexer, &parser->header))
		++parser->lexer.error;
	/* Loop over known instructions */
	else
		ft_parse_loop(parser, &parser->lexer);
	return (parser->lexer.error);
}

