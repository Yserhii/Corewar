#include "vm.h"

void	show_winner(t_vm *vm)
{
	if (vm->last_say_live)
		ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_say_live, vm->bot[vm->last_say_live - 1]->name);
	else
	{
		ft_printf("ALL GAME OVER!!!\n");
	}

}

void	print_map(t_vm *vm)
{
	// /////////////////////для печати//////////////

	for(int i = 0, k = -1; i < 64; i++)
	{
		for(int l = 0; l < 64; l++)
			ft_printf("%02x ", vm->map[++k]);
		ft_printf("\n");
	}
// 	//////////////////
}

void	print_adv(t_vm *vm, int start, int end)
{
	int		delta;
	int		i;

	if (vm->v_fl == 16 || vm->v_fl == 30)
	{
		delta = (end - start < 0) ? MEM_SIZE - start + end : end - start;
		ft_printf("ADV %d (0x%04x -> 0x%04x)", delta, start, end);
		i = -1;
		while (++i < delta)
			ft_printf(" %02x", vm->map[(start + i) % MEM_SIZE]);
		ft_printf("\n");
	}
}
