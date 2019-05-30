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
			vm->last_say_live = kar->bot_id;
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

	check_count = 0;
	while (vm->cycles_to_die > 0 && count_alive_kar(vm) > 0)
	{
		vm->cycles_from_start++;
		kar = vm->kar;
		while (kar)
		{
			// SERG
			// if (!vm->kar->cicles_to_wait)
			// 	op_recognize(vm, kar); // insert if op_live -> vm->num_of_life++
			// else
			// {
			// 	vm->kar->cicles_to_wait--;
			// 	if (!vm->kar->cicles_to_wait)
			// 	{
			// 		(*g_opers[kar->op_id])(vm, kar);
			// 		continue ;
			// 	}
			// }
			//ALEX
			if (!vm->kar->cicles_to_wait)
			{
				if (kar->op_id >= 0x01 && kar->op_id <= 0x10)
					if (valid_op_arg(vm, kar))
						(*g_opers[kar->op_id])(vm, kar);
				op_recognize(vm, kar);
			}

			//if (vm->kar->cicles_to_wait > 0)
			else
				vm->kar->cicles_to_wait--;
			kar = kar->next;
		}
		// CYCLES_TO_DIE modify
		if (vm->num_of_life >= NBR_LIVE && !(vm->num_of_life = 0))
			vm->cycles_to_die -= CYCLE_DELTA;
		if (check_count > MAX_CHECKS && !(check_count = 0))
			vm->cycles_to_die -= CYCLE_DELTA;
		// PROVERKA
		if (vm->cycles_to_die <= 0 || !(vm->cycles_from_start % vm->cycles_to_die))
		{
			vm->num_of_life = 0;
			check_count++;
			killing_check(vm);
		}
	}
}


