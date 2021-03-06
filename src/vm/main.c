/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:52:25 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/15 13:52:27 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "visual.h"

void	fun_for_help(void)
{
	ft_printf("{cyan}Usage: ./corewar [-dump N -v N | -ncurs] ");
	ft_printf("[[-n N] champion1.cor] ...\n");
	ft_printf("-dump N   : Dumps memory after N cycles then exits\n");
	ft_printf("-n    N   : sets the number N of the next player\n");
	ft_printf("-v    N   : Verbosity levels\n");
	ft_printf("            - 2 : Show cycles\n");
	ft_printf("            - 4 : Show operations\n");
	ft_printf("            - 8 : Show deaths\n");
	ft_printf("            - 16 : Show PC movements (Except for jumps)\n");
	ft_printf("            - 30 : Show all levels at once\n");
	ft_printf("-a        : print output in aff operation\n");
	ft_printf("-64       : print output 64 octets\n");
	ft_printf("-lld      : lld function reads like in original corewar\n");
	ft_printf("-leaks    : write leaks in leaks.txt\n");
	ft_printf("-ncurs    : Ncurses output mode{eoc}\n");
	exit(1);
}

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
		vm_exit(9);
	read_valid_av(ac, av, vm);
	if (vm->ncurs && start_menu())
		exit(0);
	read_valid_bot(vm);
	initialization_map(vm);
	if (vm->ncurs)
		init_visual(vm);
	battle(vm);
	if (vm->leaks_fl)
		system("leaks -q corewar > leaks.txt");
	return (0);
}
