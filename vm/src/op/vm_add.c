/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:59:13 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 15:59:16 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_add(t_vm *vm, t_kar *kar)
{
	int			reg1;
	int			reg2;
	int			reg3;
	uint8_t		arg[4];

	ft_bzero(arg, 4 * sizeof(uint8_t));
	check_argv_for_op(arg, vm, kar);
	if (arg[0] == REG_CODE && arg[1] == REG_CODE && arg[2] == REG_CODE) // && !arg[3])
	{
		reg1 = kar->reg[vm->map[(kar->pos + 2) % MEM_SIZE]];
		reg2 = kar->reg[vm->map[(kar->pos + 3) % MEM_SIZE]];
		reg3 = kar->reg[vm->map[(kar->pos + 4) % MEM_SIZE]];
		if (reg1 >= 0x0 && reg1 <= 0x16 && reg2 >= 0x0 && reg2 <= 0x16 && reg3 >= 0x0 && reg3 <= 0x16)
		{
			kar->reg[reg3] = kar->reg[reg1] + kar->reg[reg2];
			kar->carry = (!kar->reg[reg3] ? 1 : 0);
		}
	}
	kar->pos = (kar->pos + step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
}
