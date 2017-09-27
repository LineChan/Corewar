/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/27 08:36:32 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "ft_disass.h"
#include "endian.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_read_header(t_disass *dsm, int const fd)
{
	read(fd, &dsm->header.magic, sizeof(dsm->header.magic));
	dsm->header.magic = ft_endian_convert_uint32(dsm->header.magic); 
	if (COREWAR_EXEC_MAGIC != dsm->header.magic)
	{
		fprintf(stderr, "This is not a champion (wrong magic: ");
		fprintf(stderr, "%#8x instead of ", dsm->header.magic);
		fprintf(stderr, "%d)\n", COREWAR_EXEC_MAGIC);
		return ;
	}
	read(fd, dsm->header.prog_name, sizeof(t_header) - sizeof(dsm->header.magic));
	dsm->header.prog_size = ft_endian_convert_uint32(dsm->header.prog_size);
}

void	ft_disass(t_disass *dsm, int const fd)
{
	t_instr_list	*list;
	void			*data;
	char			*pc;

	ft_read_header(dsm, fd);
	data = malloc(dsm->header.prog_size);
	read(fd, data, dsm->header.prog_size);
	pc = (char *)data;
	while (dsm->header.prog_size > (pc - (char *)data))
	{
		list = (t_instr_list *)malloc(sizeof(t_instr_list));
		list->instr = ft_instruction_get(pc);
		ft_list_add_tail(&list->list, &dsm->instr_head);
		pc += list->instr->instr_size;
	}
	free(data);
	close(fd);
	{
		t_list *it;

		it = dsm->instr_head.next;
		while (it != &dsm->instr_head)
		{
			printf("Instruction [%s] (%zu bytes)\n", C_INSTR(it)->name, C_INSTR(it)->instr_size);
			it = it->next;
		}
	}
}

int main(int argc, char **argv)
{
	t_disass	dsm;
	char		*file;
	int			fd;

	INIT_LIST_HEAD(dsm.instr_head);
	dsm.opt = ft_option_new(argc, argv);
	ft_option_add_rule(dsm.opt, "--help", OPTION_KEY_BOOL);
	ft_option_add_rule(dsm.opt, "--source", OPTION_KEY_STRING);
	ft_option_add_rule(dsm.opt, "--dest", OPTION_KEY_STRING);
	ft_option_parse(dsm.opt);
	if (0 != ft_option_find(dsm.opt, "--help"))
		printf("Usage: ./%s \"--name=file.cor\"--dest=file.s\"\n", argv[0]);
	else
	{
		if (0 == (file = ft_option_find(dsm.opt, "--source")))
			fprintf(stderr, "dsm.option --source is missing\n");
		else if (-1 == (fd = open(file, O_RDONLY)))
			fprintf(stderr, "Can't open file: \"%s\"\n", file);
		else
			ft_disass(&dsm, fd);
	}
	ft_option_del(&dsm.opt);
	return (0);
}
