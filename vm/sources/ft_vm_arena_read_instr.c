
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
										t_dead_pool *dead_pool,
										const int nb_champion)
{
	unsigned int		done_champion;
	unsigned int		current_cycle;

	ft_printf("nb_champion : %d\n", nb_champion);
	ft_printf("Read instruction :\n");
	current_cycle = 0;
	done_champion = 0;
	if (dead_pool->champion1.pc && (dead_pool->champion1.cycle <= current_cycle))
	{
		ft_printf("Champion1 : %s\n", dead_pool->header1.prog_name);
		ft_vm_instr_decode(arena, &dead_pool->champion1);
	}
	if (dead_pool->champion2.pc && (dead_pool->champion2.cycle <= current_cycle))
	{
		ft_printf("\nChampion2 : %s\n", dead_pool->header2.prog_name);
		ft_vm_instr_decode(arena, &dead_pool->champion2);
	}
	if (dead_pool->champion3.pc && (dead_pool->champion3.cycle <= current_cycle))
	{
		ft_printf("\nChampion3 : %s\n", dead_pool->header3.prog_name);
		ft_vm_instr_decode(arena, &dead_pool->champion3);
	}
	if (dead_pool->champion4.pc && (dead_pool->champion4.cycle <= current_cycle))
	{
		ft_printf("\nChampion4 : %s\n", dead_pool->header4.prog_name);
		ft_vm_instr_decode(arena, &dead_pool->champion4);
	}
	ft_printf("\n");
}
