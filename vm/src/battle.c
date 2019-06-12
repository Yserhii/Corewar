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

int check_battle_constants(void)
{
	return ((CYCLE_DELTA < 1 || NBR_LIVE < 1) ? 0 : 1);
}

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
	ft_printf("ALIVE KARS: ");
	while (kar)
	{
		if (kar->live)
			ft_printf("[%d] ", kar->id);
		if (!kar->next)//////////////////////////////////////////////
			break ;//////////////////////////////////////////////////
		kar = kar->next;
	}
	// go to end
	// kar = vm->kar;//////////////////////////////////////////////////////////
	// while (kar && kar->next)///////////////////////////////////////////
		// kar = kar->next;///////////////////////////////////////////////////
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
	// t_kar	*tmp;

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
		// tmp = kar->next;///////////////////////////////////////////
		// kar->back->next = kar->next;//////////////////////////////
		// tmp->back = kar->back;///////////////////////////////////
		kar->next->back = kar->back;/////////////////////////////////
		kar->back->next = kar->next;////////////////////////////////
	}
}

void killing_check(t_vm *vm)
{
	t_kar	*kar;
	t_kar	*tmp;

	// ft_printf("\t\t\tKILLING check\n");
	kar = vm->kar;
	while(kar)
	{
		tmp = kar->next;
		if (!kar->live)
		{
			ft_kar_del(vm, kar);
			// OUTPUT V_FLAG = 8
			if (vm->v_fl == 8 || vm->v_fl == 30)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					kar->id, vm->cycles_from_start - kar->last_time_said_live, vm->cycles_to_die);
			// ft_show_alive_kars_tmp(vm);
			free(kar);
		}
		else
			kar->live = 0;
		kar = tmp;
	}
}

void	battle(t_vm *vm)
{
	t_kar	*kar;
	int		check_count;
	// if (!check_battle_constants())
	// 	exit(ft_printf("Battle constants ERROR\n"));
	//print_map(vm);
	check_count = 0;

	// init OPERATIONS kars
	kar = vm->kar;
	while (kar)
	{
		op_recognize(vm, kar);
		if (kar->cicles_to_wait > 0) // ALEX
			kar->cicles_to_wait--;
		kar = kar->next;
	}

	// vm->cycles_from_start = 1;
	while (vm->cycles_to_die > 0 && count_alive_kar(vm) > 0)
	{
		// OUTPUT V_FLAG = 2

		// DUMP check
		if ((vm->nbr_cycles > -1 && vm->cycles_from_start >= vm->nbr_cycles))
		{
			print_map(vm);
			break;
		}

		vm->cycles_from_start++;

		if (vm->v_fl == 2 || vm->v_fl == 30)
			ft_printf("It is now cycle %d\n", vm->cycles_from_start);
		// ft_printf("%d", vm->map[kar->pos]);

		kar = vm->kar;

		while (kar)
		{
		 	// ft_printf("\t****pos[%d] = %02d", kar->pos, vm->map[kar->pos]);
			// SERG
			// if (kar->cicles_to_wait <= 0)
			// 	op_recognize(vm, kar); // insert if op_live -> vm->num_of_life++
			// kar->cicles_to_wait--;
			// if (!kar->cicles_to_wait)
			// 	(*g_opers[kar->op_id])(vm, kar);
			//ALEX
			if (!kar->cicles_to_wait)
			{
				if (kar->op_id >= 0x01 && kar->op_id <= 0x10)
					(*g_opers[kar->op_id])(vm, kar);
				op_recognize(vm, kar);
			}
			if (kar->cicles_to_wait > 0) // ALEX
				kar->cicles_to_wait--;
			if (vm->ncurs && !(vm->cycles_from_start % 3))
				visualisation(vm);
			kar = kar->next;
		}
		// PROVERKA
		if (!(vm->cycles_from_start % vm->cycles_to_die))
		{
			// CYCLES_TO_DIE modify
			if (vm->num_of_life >= NBR_LIVE && !(vm->num_of_life = 0))
				vm->cycles_to_die -= CYCLE_DELTA;
			if (check_count > MAX_CHECKS && !(check_count = 0))
				vm->cycles_to_die -= CYCLE_DELTA;
			//////////////////////
			vm->num_of_life = 0;
			check_count++;
			killing_check(vm);
		}
	}
	if ((vm->nbr_cycles == -1 || vm->cycles_from_start < vm->nbr_cycles) && !vm->ncurs)
		show_winner(vm);
	if (vm->ncurs)
	{
		show_winner_vis(vm);
		getch();
		endwin();
	}
}
