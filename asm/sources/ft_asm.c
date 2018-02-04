/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 16:04:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_asm.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static void	ft_assemble_dump(t_parser *parser)
{
	static char	const *kind_name[] = { "unknow", "T_REG", "T_DIR", "unknow", "T_IND" };
	t_statement	*st;
	t_list		*it;
	int			i;
	uint8_t		*p;

	it = parser->statement_head.next;
	while (it != &parser->statement_head)
	{
		/* Get instruction */
		st = C_STATEMENT(it);
		ft_printf("Instruction {bblack:%s}:\n", st->instr->op->name);
		i = 0;
		/* Display instruction informations block */
		while (i < st->instr->op->nb_args)
		{
			ft_printf("  (%d) line: {bblack:%2d}, pos: {bblack:%2d}, type: {bblack:%s}, bytes: {bblack:%d}, data: \"{bblack:%s}\"\n",
				i + 1, st->token[i]->loc.line + 1, st->token[i]->loc.pos + 1,
				kind_name[st->token[i]->kind], st->instr->args[i].size, st->token[i]->data->str);
			++i;
		}
		ft_printf("  Total size: {bblack:%d bytes}\n", st->instr->instr_size);
		/* Display the binary output */
		ft_printf("  Binary: [{red:%02hhx}]", st->instr->op->numero);
		if (0 != st->instr->op->param_byte)
			ft_printf(" [{cyan:%02hhx}]", st->instr->bytecode);
		i = 0;
		while (i < st->instr->op->nb_args)
		{
			p = (uint8_t *)st->instr->args[i].data;
			if (1 == st->instr->args[i].size)
				ft_printf(" [{yellow:%02hhx}]", p[0]);
			else if (2 == st->instr->args[i].size)
				ft_printf(" [{yellow:%02hhx %02hhx}]", p[0], p[1]);
			else if (4 == st->instr->args[i].size)
				ft_printf(" [{yellow:%02hhx %02hhx %02hhx %02hhx}]", p[0], p[1], p[2], p[3]);
			++i;
		}
		ft_printf("\n\n");
		it = it->next;
	}
}

static void	ft_assemble(int fd, t_parser *parser)
{
	t_instr	*instr;
	t_list	*it;
	int		i;
	int8_t	c;

	/* Write the header in one block */
	write(fd, &parser->header, sizeof(t_header));
	/* For each statement parsed */
	it = parser->statement_head.next;
	while (it != &parser->statement_head)
	{
		/* get the encoded instruction */
		instr = C_STATEMENT(it)->instr;
		/* write the instruction number, using unsigned char type */
		c = instr->op->numero;
		write(fd, &c, sizeof(c));
		/* write the bytecode, already stored as unsigned char */
		if (0 != instr->op->param_byte)
			write(fd, &instr->bytecode, sizeof(instr->bytecode));
		/* for each paramaters of the instruction */
		i = 0;
		while (i < instr->op->nb_args)
		{
			/* Write the data with the size associed */
			write(fd, instr->args[i].data, instr->args[i].size);
			++i;
		}
		/* next instruction */
		it = it->next;
	}
}

void		ft_asm(char const *file_in, char const *file_content, int dump)
{
	t_string	*file_out;
	t_parser	parser;
	struct stat st;
	int			fd_out;

	/* Parse the file_content */
	if (0 == ft_parse(&parser, file_in, file_content))
	{
		if (0 != dump)
			ft_assemble_dump(&parser);
		/* Copy up to len - 2 chars to skip the '.s' suffix */
		file_out = ft_string_ndup(file_in, ft_strlen(file_in) - 2);
		/* add the suffix for compiled object */
		ft_string_cat(file_out, ".cor");
		/* Check if file exist and get the length. */
		if (0 <= stat(file_out->str, &st))
			ft_fprintf(ft_stderr, "File {red:%s} already exist\n", file_out->str);
		else
		{
			/* Try to open the destination file */
			fd_out = open(file_out->str, O_WRONLY | O_CREAT, 0644);
			if (0 > fd_out)
				ft_fprintf(ft_stderr, "Can't open destination file '%s'\n", file_out->str);
			else
			{
				/* Assemble the parsed code and close the file descriptor */
				ft_assemble(fd_out, &parser);
				ft_printf("Writing output program to %s\n", file_out->str);
				close(fd_out);
			}
		}
		/* Cleanup memory */
		ft_parser_del(&parser);
		ft_string_del(&file_out);
	}
}
