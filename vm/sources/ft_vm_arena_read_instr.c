
# include "ft_vm.h"
// TODO : presentation
/*
* brief      		Set up the virtual machine
*
* param arena		Memory dedicated to the virtual machine
* param option		Options' array
* param dead_pool	Structure gatehering all the champions
* param nb_champion	Champions number
*/

extern uint8_t	g_direct_jump_table_from_instr[17];

void			ft_vm_arena_read_instr(unsigned char arena[],
										t_dead_pool *dead_pool)
{
	ft_printf("dead_pool : %s\n", dead_pool->champion1.prog_name);
	if (PC_1)
	{
		ft_printf("Champion1\n");
		ft_vm_instr_decode(arena, CHAMP_1);
		//ft_printf("PC_1 : %s\n", g_op_tab[*PC_1].name);
	}
	if (PC_2)
	{
		ft_printf("\nChampion2\n");
		ft_vm_instr_decode(arena, CHAMP_2);
		//ft_printf("PC_2 : %s\n", g_op_tab[*PC_2].name);
	}
	if (PC_3)
	{
		ft_printf("\nChampion3\n");
		ft_vm_instr_decode(arena, CHAMP_3);
	}
	if (PC_4)
	{
		ft_printf("\nChampion4\n");
		ft_vm_instr_decode(arena, CHAMP_4);
	}
	ft_printf("\n");
}
