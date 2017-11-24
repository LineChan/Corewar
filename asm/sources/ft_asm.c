/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/17 20:55:13 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_asm.h"
#include <fcntl.h>
#include <unistd.h>

static void	ft_assemble_arg(int fd, char const *data, size_t size)
{
	uint32_t	arg;
	uint16_t	s;
	uint8_t		c;

	arg = *(uint32_t *)data;
	if (1 == size)
	{
		c = (uint8_t)arg;
		write(fd, &c, size);
	}
	else if (2 == size)
	{
		s = (uint16_t)arg;
		write(fd, &s, size);
	}
	else if (4 == size)
		write(fd, &arg, size);
}

static void	ft_assemble(int fd, t_parser *parser)
{
	t_instr	*instr;
	t_list	*it;
	int		i;
	uint8_t	c;

	/* Write the header in one block */
	write(fd, &parser->header, sizeof(t_header));

	it = parser->statement_head.next;
	while (it != &parser->statement_head)
	{
		/* get the encoded instruction */
		instr = C_STATEMENT(it)->instr;

		/* write the instruction number */
		c = instr->op->numero;
		write(fd, &c, sizeof(c));

		/* write the bytecode */
		if (0 != instr->op->param_byte)
		{
			c = instr->bytecode;
			write(fd, &c, sizeof(c));
		}

		/* for each paramaters of the instruction */
		i = 0;
		while (i < instr->op->nb_args)
		{
			/* Assemble the argument */
			ft_assemble_arg(fd, instr->args.encode[i].data,
								instr->args.encode[i].size);
			++i;
		}

		/* next instruction */
		it = it->next;
	}
}

void		ft_asm(char const *file_in, char const *file_content)
{
	t_string	*file_out;
	t_parser	parser;
	int			fd_out;

	/* Parse the file_content */
	if (0 != ft_parse(&parser, file_in, file_content))
	{
		/* Copy up to len - 2 chars */
		file_out = ft_string_ndup(file_in, ft_strlen(file_in) - 2);
		ft_string_cat(file_out, ".cor");

		/* Try to open the destination file */
		fd_out = open(file_out->str, O_WRONLY | O_CREAT, 0644);
		if (0 < fd_out)
		{
			/* Assemble the parsed code */
			ft_assemble(fd_out, &parser);
			close(fd_out);
		}
		else
			ft_fprintf(ft_stderr, "Can't open destination file '%s'\n", file_out->str);
		ft_parser_del(&parser);
		ft_string_del(&file_out);
	}
}
