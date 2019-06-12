/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:55:49 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 15:55:52 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_live(t_vm *vm, t_kar *kar)
{
	int		arg;

	arg = take_arg(vm, (kar->pos + 1), 4);
	if ((int)kar->bot_id == ABS(arg))
		vm->last_say_live = kar->bot_id;
	kar->live = vm->cycles_from_start;
	vm->num_of_life++;
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | live %d\n", kar->id, arg);
	print_adv(vm, kar->pos, kar->pos = (kar->pos +
					g_op[kar->op_id].dir_size + 1) % MEM_SIZE);
}


///////////////////////////////////////////////////////////////////////////////////////


// void	vm_live(t_vm *vm, t_kar *kar)
// {
// 	int		arg;

// 	arg = take_arg(vm, (kar->pos + 1), 4);
// 	// arg = (vm->map[(kar->pos + 1) % MEM_SIZE] << 24) + (vm->map[(kar->pos + 2)
// 	// 	% MEM_SIZE] << 16) + (vm->map[(kar->pos + 3) % MEM_SIZE] << 8) +
// 	// 		vm->map[(kar->pos + 4) % MEM_SIZE];
// 	if ((int)kar->bot_id == ABS(arg))
// 	{
// 		vm->last_say_live = kar->bot_id;
// 	}
// 	kar->live = vm->cycles_from_start;
// 	// ft_printf("==== %d\n", vm->cycles_from_start);
// 	// kar->last_time_said_live = vm->cycles_from_start;
// 	vm->num_of_life++;
// 	if (vm->v_fl == 4 || vm->v_fl == 30)
// 		ft_printf("P% 5d | live %d\n", kar->id, arg);
// 	print_adv(vm, kar->pos, kar->pos = (kar->pos + g_op[kar->op_id].dir_size + 1) % MEM_SIZE);
// 	return ;
// }
