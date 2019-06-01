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

void	show_winner(t_vm *vm)
{
	ft_printf("Winner is %s\n", vm->bot[vm->last_say_live]->name); // ? name is not a string?
}

void killing_check(t_vm *vm)
{
	t_kar	*kar;
	t_kar	*tmp;

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
	print_map(vm);
	check_count = 0;
	while (vm->cycles_to_die > 0 && count_alive_kar(vm) > 0)
	{
		vm->cycles_from_start++;
		ft_printf("\t CYCLE: %d\n", vm->cycles_from_start);
		kar = vm->kar;
		while (kar)
		{
			// SERG
			if (!kar->cicles_to_wait)
				op_recognize(vm, kar); // insert if op_live -> vm->num_of_life++
			kar->cicles_to_wait--;
			if (!kar->cicles_to_wait)
				(*g_opers[kar->op_id])(vm, kar);


			//ALEX
			// if (!kar->cicles_to_wait)
			// {
			// 	if (kar->op_id >= 0x01 && kar->op_id <= 0x10)
			// 		(*g_opers[kar->op_id])(vm, kar);
			// 	op_recognize(vm, kar);
			// }
			// if (kar->cicles_to_wait > 0) // ALEX
			// 	kar->cicles_to_wait--;
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
		// DUMP finish
		if (vm->nbr_cycles > -1 && vm->cycles_from_start >= vm->nbr_cycles)
		{
			// print_map(vm);
			break;
		}
	}
	if (vm->nbr_cycles == -1)
	{
		// print_map(vm);
		show_winner(vm);
	}

}


