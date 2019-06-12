/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:10:08 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/25 20:10:12 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
// make && ./corewar -v 30  ../../42-corewar/tests/vm/error/zork_lt_size.s.cor  > out.txt && ./test/corewar_orig -v 30 ../../42-corewar/tests/vm/error/zork_lt_size.s.cor > out_orig.txt && diff out.txt out_orig.txt > diff.txt


//  make && ./test/asm_orig test/bot_test.s && ./corewar -v 30 -dump 30000 test/bot_test.cor test/bot_test.cor> out.txt && ./test/corewar_orig -v 30 -d 30000 test/bot_test.cor test/bot_test.cor> out_orig.txt && diff out.txt out_orig.txt > diff.txt


int count_alive_kar(t_vm *vm)
{
	t_kar *kar;
	int i;

	i = 0;
	kar = vm->kar;
	while (kar && ++i)
		kar = kar->next;
	return (i);
}

void	ft_show_alive_kars_tmp(t_vm *vm)
{
	t_kar	*kar;

	kar = vm->kar;
	ft_printf("\tALIVE KARS: ");
	while (kar)
	{
		ft_printf("#%d - %d[%02x] ", kar->id, kar->pos, vm->map[kar->pos]);
		if (!kar->next)
			break ;
		kar = kar->next;
	}
	ft_printf("ALIVE KARS backwards: ");
	while (kar)
	{
		ft_printf("[%d] ", kar->id);
		kar = kar->back;
	}
	ft_printf("\n");
}

void	ft_kar_del(t_vm *vm, t_kar *kar)
{
	if (!kar->back && !kar->next)
		vm->kar = NULL;
	else if (!kar->back)
	{
		vm->kar = kar->next;
		vm->kar->back = NULL;
	}
	else if (!kar->next)
		kar->back->next = NULL;
	else
	{
		kar->next->back = kar->back;
		kar->back->next = kar->next;
	}
}

void killing_kars(t_vm *vm)
{
	t_kar	*kar;
	t_kar	*tmp;

	kar = vm->kar;
	while(kar)
	{
		tmp = kar->next;
		if (vm->cycles_from_start - kar->live >= vm->cycles_to_die)
		{
			ft_kar_del(vm, kar);
			if (vm->v_fl == 8 || vm->v_fl == 30)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					kar->id, vm->cycles_from_start - kar->live, vm->cycles_to_die);
			free(kar);
		}
		kar = tmp;
	}
}

void	battle_proverka(t_vm *vm, int *cycle_to_die)
{
	if (vm->cycles_to_die <= 0 || (vm->cycles_after_check == vm->cycles_to_die))
	{
		killing_kars(vm);
		vm->check_count++;
		*cycle_to_die = vm->cycles_to_die;
		if (vm->check_count == MAX_CHECKS || vm->num_of_life >= NBR_LIVE)
		{
			vm->cycles_to_die -= CYCLE_DELTA;
			vm->check_count = 0;
		}
		vm->num_of_life = 0;
		vm->cycles_after_check = 0;
		if ((vm->v_fl == 2 || vm->v_fl == 30) && vm->cycles_to_die != *cycle_to_die)
			ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
	}
}

void	battle(t_vm *vm)
{
	t_kar	*kar;
	int		cycle_to_die;

	cycle_to_die = CYCLE_TO_DIE;
	while (count_alive_kar(vm) > 0) // (vm->cycles_to_die > 0 && count_alive_kar(vm) > 0)
	{
		if ((vm->nbr_cycles > -1 && vm->cycles_from_start >= vm->nbr_cycles))
		{
			print_map(vm);
			break;
		}
		vm->cycles_from_start++;
		vm->cycles_after_check++;
		if (vm->v_fl == 2 || vm->v_fl == 30)
			ft_printf("It is now cycle %d\n", vm->cycles_from_start);
		kar = vm->kar;
		while (kar)
		{

			if (kar->cicles_to_wait == 0)
				op_recognize(vm, kar);
			if (kar->cicles_to_wait > 0)
				kar->cicles_to_wait--;
			if (kar->cicles_to_wait == 0)
			{
				if (kar->op_id >= 0x01 && kar->op_id <= 0x10)
					(*g_opers[kar->op_id])(vm, kar);
				else
					kar->pos = (kar->pos + 1) % MEM_SIZE;
			}
			if (vm->ncurs)
				visualisation(vm);
			kar = kar->next;
		}
		// PROVERKA
		battle_proverka(vm, &cycle_to_die);
		// if (vm->cycles_to_die <= 0 || (vm->cycles_after_check == vm->cycles_to_die))
		// {
		// 	killing_kars(vm);
		// 	vm->check_count++;
		// 	cycle_to_die = vm->cycles_to_die;
		// 	if (vm->check_count == MAX_CHECKS || vm->num_of_life >= NBR_LIVE)
		// 	{
		// 		vm->cycles_to_die -= CYCLE_DELTA;
		// 		vm->check_count = 0;
		// 	}
		// 	vm->num_of_life = 0;
		// 	vm->cycles_after_check = 0;
		// 	if ((vm->v_fl == 2 || vm->v_fl == 30) && vm->cycles_to_die != cycle_to_die)
		// 		ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
		// }
	}
	if (vm->nbr_cycles == -1 || vm->cycles_from_start < vm->nbr_cycles)
		show_winner(vm);
	if (vm->ncurs)
	{
		getch();
		endwin();
	}
}
