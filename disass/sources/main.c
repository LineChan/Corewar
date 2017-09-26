/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/27 01:23:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "ft_disass.h"
#include "endian.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_read_file(t_disass *dsm, int const fd)
{
	read(fd, &dsm->header.magic, sizeof(dsm->header.magic));
	dsm->header.magic = ft_endian_convert_uint32(dsm->header.magic); 
	if (COREWAR_EXEC_MAGIC != dsm->header.magic)
	{
		fprintf(stderr, "This is not a champion (wrong magic: %#8x instead of %d)\n", dsm->header.magic, COREWAR_EXEC_MAGIC);
		return ;
	}
	read(fd, dsm->header.prog_name, sizeof(t_header) - sizeof(dsm->header.magic));
	dsm->header.prog_size = ft_endian_convert_uint32(dsm->header.prog_size);
	dsm->data = malloc(dsm->header.prog_size);
	read(fd, dsm->data, dsm->header.prog_size);
}

void	ft_disass(t_disass *dsm, int const fd)
{
	t_instr	*ist;
	char	*pc;

	ft_read_file(dsm, fd);
	close(fd);
	pc = (char *)dsm->data;
	while (dsm->header.prog_size > (pc - (char *)dsm->data))
	{
		ist = ft_instruction_get(pc);
		pc += ist->instr_size;
		ft_instruction_del(&ist);
	}
}

int main(int argc, char **argv)
{
	t_disass	dsm;
	char		*file;
	int			fd;

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
