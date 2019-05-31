/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:56:18 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 15:56:20 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_ld(t_vm *vm, t_kar *kar)
{
	uint8_t		arg[4];
	ft_printf("vm_ld\n");
	kar->pos += g_op[kar->op_id].is_args_types;
	arg[0] = (vm->map[kar->pos] >> 6 & 0x3);
	arg[1] = (vm->map[kar->pos] >> 4 & 0x3);
	arg[2] = (vm->map[kar->pos] >> 2 & 0x3);
	arg[3] = (vm->map[kar->pos] & 0x3);
	ft_printf("%d\n", arg[0]);
	ft_printf("%d\n", arg[1]);
	ft_printf("%d\n", arg[2]);
	ft_printf("%d\n", arg[3]);

	if ((arg[0] == DIR_CODE || arg[0] == IND_CODE) && (arg[1] == REG_CODE) && !arg[2] && !arg[3])
	{
		if (arg[0] == DIR_CODE)
		{
			ft_printf("dir and reg\n");
		}
		else
		{
			ft_printf("ind and reg\n");
		}
	}
	else
	{
		ft_printf("error\n");
	}







	// // arg = get_arg_live(vm->map, (kar->pos + 1) % MEM_SIZE, g_op[kar->op_id - 1].dir_size);
	// kar->pos += g_op[kar->op_id].is_args_types;
	// arg = vm->map[(g_op[kar->op_id].is_args_types + 1) % MEM_SIZE];
	// if (kar->bot_id == arg)
	// {
	// 	vm->last_say_live = kar->bot_id;
	// 	kar->live = vm->cycles_from_start;
	// }
	// vm->num_of_life++; //вне цыкла;
	kar->pos += 6;
	// return ;

	(void)kar;
	(void)vm;
	return ;
}
