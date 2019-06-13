/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:59:23 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 15:59:26 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void static inline	v_flag_4_or_v_flag_30(t_vm *vm, t_kar *kar)
{
	ft_printf("P% 5d | sub r%d r%d r%d\n", kar->id,
								vm->map[(kar->pos + 2) % MEM_SIZE],
									vm->map[(kar->pos + 3) % MEM_SIZE],
										vm->map[(kar->pos + 4) % MEM_SIZE]);
}

void				vm_sub(t_vm *vm, t_kar *kar)
{
	int			reg1;
	int			reg2;
	int			reg3;
	uint8_t		kod[4];

	ft_bzero(kod, 4 * sizeof(uint8_t));
	check_argv_for_op(kod, vm, kar);
	if (kod[0] == REG_CODE && kod[1] == REG_CODE && kod[2] == REG_CODE)
	{
		reg1 = vm->map[(kar->pos + 2) % MEM_SIZE];
		reg2 = vm->map[(kar->pos + 3) % MEM_SIZE];
		reg3 = vm->map[(kar->pos + 4) % MEM_SIZE];
		if (reg1 > 0 && reg1 < 17 && reg2 > 0 && reg2 < 17 &&
														reg3 > 0 && reg3 < 17)
		{
			kar->reg[reg3] = kar->reg[reg1] - kar->reg[reg2];
			kar->carry = (!kar->reg[reg3] ? 1 : 0);
			if (vm->v_fl == 4 || vm->v_fl == 30)
				v_flag_4_or_v_flag_30(vm, kar);
		}
	}
	print_adv(vm, kar->pos,
		kar->pos += step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg));
}
