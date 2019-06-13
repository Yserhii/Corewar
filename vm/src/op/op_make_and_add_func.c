/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_make_and_add_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:02:22 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/28 13:02:25 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		give_reg_to_map(t_vm *vm, int pos, t_kar *kar, uint32_t src)
{
	int	size_arg;

	size_arg = 4;
	while (size_arg)
	{
		vm->map[pos % MEM_SIZE] = src >> (8 * --size_arg) & 0xff;
		vm->inf_vis[pos++ % MEM_SIZE] = kar->bot_id;
	}
}

int			step_for_not_valid(uint8_t *arg, t_kar *kar, int num_arg)
{
	int i;

	i = 0;
	while (--num_arg != -1)
	{
		if (arg[num_arg] == REG_CODE)
			i += REG;
		else if (arg[num_arg] == DIR_CODE)
			i += g_op[kar->op_id].dir_size;
		else if (arg[num_arg] == IND_CODE)
			i += IND;
	}
	i += (g_op[kar->op_id].is_args_types + 1);
	return (i);
}

void		check_argv_for_op(uint8_t *arg, t_vm *vm, t_kar *kar)
{
	arg[0] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 6 & 0x3);
	arg[1] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 4 & 0x3);
	arg[2] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 2 & 0x3);
	arg[3] = (vm->map[(kar->pos + 1) % MEM_SIZE] & 0x3);
}

void		op_recognize(t_vm *vm, t_kar *kar)
{
	kar->op_id = vm->map[kar->pos];
	if (vm->map[kar->pos] >= 0x01 && vm->map[kar->pos] <= 0x10)
		kar->cicles_to_wait = g_op[kar->op_id].wait;
}
