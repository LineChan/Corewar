/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:09:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 18:24:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"

#if 0
unsigned char *p_arena;
unsigned char *p_register;
size_t i;

i = 0;
p_arena = (unsigned char *)arena;
p_register = (unsigned char *)&register[0];
while (i < sizeof(int))
{
    *p_arena = *p_register++;
    p_arena = arena[MOD(p_arena - arena + 1)];
    ++i;
}
#endif
//TODO : libs
#include "ft_printf.h"
void			ft_vm_instr_st_data(t_vm *vm,
									const unsigned char *ptr,
									int *reg)
{
	unsigned char	*p_arena;
	unsigned char	*p_reg;
	//int8_t			tmp;
	size_t 			i;

	#if 0
	if ((ptr - vm->arena[0]) < (MEM_SIZE - REG_SIZE))
	{
		if (IS_BIG_ENDIAN)
		{
			ft_printf("BIG ENDIAN\n");
			*(unsigned int *)ptr = *(unsigned int *)reg;
		}
		else
		{
			*(unsigned int *)ptr = ft_endian_convert_int32(*(unsigned int *)reg);
			ft_printf("NOT BIG ENDIAN\n");
		}


		ft_printf("not the end of the arena\n");
		ft_printf("ptr : %d\n", (int)*ptr);
		ft_printf("reg : %x\n", (int)*reg);
		*(unsigned int *)ptr = *(unsigned int *)reg;
		ft_printf("ptr : %d\n", *ptr);
		return ;
	}
	#endif
	ft_printf("START : \n");
	ft_printf("reg : %x\n", *reg);
	i = 0;
	while (i < REG_SIZE)
	{
		//ft_printf("ptr[%d] : %x\n",i,  (int)*ptr);
		ft_printf("reg[%d] : %x\n",i,  (char)*reg);
		++reg;
		//++ptr;
		++i;
	}
	i = 0;
	p_arena = (unsigned char *)ptr;
	p_reg = (unsigned char *)reg;
	while (i < REG_SIZE)
	{
		ft_printf("copy! \n");
		ft_printf("arena av : %x\n", *p_arena);
		*p_arena++ = *p_reg++;
		ft_printf("arena ap : %x\n", *p_arena);
		++i;
	}
	ft_printf("p_arena : %d\n", *ptr);
	(void)vm;
	(void)ptr;
	(void)reg;
	#if 0
	uint32_t		tmp;
	int8_t			i;

	while (i < REG_SIZE)
	{

		++i;
	}
	#endif
}
