/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 12:55:46 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_printf.h"
#include "ft_string.h"
#include "endian.h"
#include <unistd.h>

/*
** Read magic number first, make sure it is the same as defined in op.h
** It not, abort the engine.
*/
static int	ft_read_header(t_disass *dsm)
{
	size_t magic_len;

	/* read magic number first, abort if it fail */
	magic_len = sizeof(dsm->header.magic);
	read(dsm->fd_in, &dsm->header.magic, magic_len);
	/* The VM is actualy BIG_ENDIAN,
	   we need to check our arch if a conversion is needed. */
	if (IS_LITTLE_ENDIAN)
		dsm->header.magic = ft_endian_convert_int32(dsm->header.magic);
	if (COREWAR_EXEC_MAGIC != dsm->header.magic)
	{
		ft_fprintf(ft_stderr, "This is not a champion (wrong magic: ");
		ft_fprintf(ft_stderr, "%#8x instead of ", dsm->header.magic);
		ft_fprintf(ft_stderr, "%d)\n", COREWAR_EXEC_MAGIC);
		return (EXIT_FAILURE);
	}
	/* read header content */
	read(dsm->fd_in, dsm->header.prog_name, sizeof(t_header) - magic_len);
	if (IS_LITTLE_ENDIAN)
		dsm->header.prog_size = ft_endian_convert_uint32(dsm->header.prog_size);
	return (EXIT_SUCCESS);
}

void		ft_disass(t_disass *dsm)
{
	t_instr_node	*instruction_list;
	uint8_t			*data;
	uint8_t			*pc;
	uint32_t		byte_pos;

	/* read header */
	if (EXIT_FAILURE == ft_read_header(dsm))
		return ;
	/* read program data */
	data = (uint8_t *)ft_memalloc(dsm->header.prog_size);
	read(dsm->fd_in, data, dsm->header.prog_size);
	pc = data;
	/* iterate over data */
	while (dsm->header.prog_size > (byte_pos = (pc - data)))
	{
		instruction_list = ft_memalloc(sizeof(t_instr_node));

		/* Set byte position instruction */
		instruction_list->byte_pos = byte_pos;
		ft_list_add_tail(&instruction_list->list, &dsm->instr_head);
		/* decode instruction from current pc */
		instruction_list->instr = ft_instruction_decode(pc);
		if (0 == instruction_list->instr)
			break ;
		/* pc jump with size of instruction to reach the next instruction */
		pc = instruction_list->instr->new_pc;
	}
	ft_memdel((void **)&data);
}
