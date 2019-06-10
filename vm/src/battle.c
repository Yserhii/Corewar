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
			if (!kar->back && !kar->next)
				vm->kar = NULL;
			else if (!kar->back && (vm->kar = kar->next))
				vm->kar->back = NULL;
			else if (!kar->next && kar->back)
				kar->back->next = NULL;
			else
			{
				kar->back->next = kar->next;
				kar->next->back = kar->back;
			}
			// OUTPUT V_FLAG = 8
			if (vm->v_fl == 8 || vm->v_fl == 30)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					kar->id, vm->cycles_from_start, vm->cycles_to_die);
			free(kar);
		}
		else
		{
			//vm->last_say_live = kar->bot_id; // ? это должно быть в операции live (скорее всего)
			kar->live = 0;
		}
		kar = tmp;
	}
}

			// if (kar->back)
			// 	kar->back->next = kar->next;
			// else
			// 	vm->kar = kar->next;
			// if (kar->next)
			// 	kar->next->back = kar->back;
			// else
			// 	kar->back->next = NULL;
			// free(kar);



void	battle(t_vm *vm)
{
	t_kar	*kar;
	int		check_count;
	// if (!check_battle_constants())
	// 	exit(ft_printf("Battle constants ERROR\n"));
	//print_map(vm);
	check_count = 0;
	while (vm->cycles_to_die > 0 && count_alive_kar(vm) > 0)
	{
		// OUTPUT V_FLAG = 2

		// DUMP check
		if ((vm->nbr_cycles > -1 && vm->cycles_from_start >= vm->nbr_cycles))
		{
			print_map(vm);
			break;
		}
		if (vm->v_fl == 2 || vm->v_fl == 30)
			ft_printf("It is now cycle %d\n", vm->cycles_from_start);
		// ft_printf("%d", vm->map[kar->pos]);
		vm->cycles_from_start++;
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
			if (vm->ncurs)
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
	// if (vm->nbr_cycles == -1)
	// 	show_winner(vm);
	// else
	// 	print_map(vm);

}
