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

// make && ./corewar -v 30 -dump 100 helltrain.cor > out.txt && ./test/corewar_orig -v 30 -d 100 helltrain.cor > out_orig.txt
// /test/corewar_orig -v 8 helltrain.cor -d 200
// make && ./corewar -v 30 -dump 10000 helltrain.cor > out.txt && ./test/corewar_orig -v 30 -d 10000 helltrain.cor > out_orig.txt && diff out.txt out_orig.txt > diff.txt
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
	ft_printf("-ncurs    : Ncurses output mode{eoc}\n");
	exit(1);
}

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
		vm_exit(9);
	if (start_menu())
		exit(0);
	read_valid_av(ac, av, vm);
	read_valid_bot(vm);
	initialization_map(vm);
	battle(vm);
	return (0);
}
