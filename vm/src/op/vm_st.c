/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:59:05 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 15:59:07 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_st(t_vm *vm, t_kar *kar)
{
	uint8_t		arg[4];
	int16_t		reg1;
	int16_t		reg2;

	ft_bzero(arg, 4 * sizeof(uint8_t));
	check_argv_for_op(arg, vm, kar);
	if (arg[0] == REG_CODE && (arg[1] == REG_CODE || arg[1] == IND_CODE))
	{
		reg1 = vm->map[(kar->pos + 2) % MEM_SIZE];
		if (arg[1] == REG_CODE)
			reg2 = (int8_t)(vm->map[(kar->pos + 3) % MEM_SIZE]);
		else
			reg2 = (short)take_arg(vm, (kar->pos + 3), 2);
		if (arg[1] == 1 && reg1 > 0 && reg1 < 17 && reg2 > 0 && reg2 < 17)
			kar->reg[reg2] = kar->reg[reg1];
		else if (arg[1] == IND_CODE && reg1 > 0 && reg1 < 17)
			give_reg_to_map(vm, (kar->pos + reg2 % IDX_MOD) % MEM_SIZE,
														kar, kar->reg[reg1]);
		if ((arg[1] == REG_CODE && reg1 > 0 && reg1 < 17 && reg2 > 0 &&
			reg2 < 17) || (arg[1] == IND_CODE && reg1 > 0 && reg1 < 17))
			if (vm->v_fl == 4 || vm->v_fl == 30)
				ft_printf("P% 5d | st r%d %d\n", kar->id, reg1, reg2);
	}
	// print_adv(vm, kar->pos, kar->pos = (kar->pos +
		// step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE);
	print_adv(vm, kar->pos, kar->pos += step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg));
	kar->pos = kar->pos % MEM_SIZE;

}
