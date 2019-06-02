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
	uint16_t	ind;
	uint8_t		reg1;
	uint8_t		reg2;

	ft_bzero(arg, 4 * sizeof(uint8_t));
	check_argv_for_op(arg, vm, kar);
	if (arg[0] == REG_CODE && (arg[1] == REG_CODE || arg[1] == IND_CODE))// && !arg[2] && !arg[3])
	{
		reg1 = kar->reg[vm->map[(kar->pos + 2) % MEM_SIZE]];
		reg2 = kar->reg[vm->map[(kar->pos + 3) % MEM_SIZE]];
		if (arg[1] == REG_CODE && reg1 >= 0x0 && reg1 <= 0x16 && reg2 >= 0x0 && reg2 <= 0x16)
				kar->reg[reg2] = kar->reg[reg1];
		else if (reg1 >= 0x0 && reg1 <= 0x16 && reg2 >= 0x0 && reg2 <= 0x16)
		{
			// ind = (vm->map[(kar->pos + 3) % MEM_SIZE] << 8) + vm->map[(kar->pos + 4) % MEM_SIZE];
			// ind = (kar->pos + ind % IDX_MOD) % MEM_SIZE;
			///////Здесь я заменил строчку ниже на новую адоптивную функции почитай над ней комент поймешь как работает!!!!!!!!!!
			ind = kar->pos + ((take_arg(vm, (kar->pos + 3), 2)) % IDX_MOD);
			///////Здесь я заменил строчку ниже на новую адоптивную функции почитай над ней комент поймешь как работает!!!!!!!!!!
			give_reg_to_map(vm, ind % MEM_SIZE, 4, kar->reg[reg1]);
			// vm->map[ind % MEM_SIZE] = kar->reg[reg1] >> 24 & 0xff;
			// vm->map[(ind + 1) % MEM_SIZE] = kar->reg[reg1] >> 16 & 0xff;
			// vm->map[(ind + 2) % MEM_SIZE] = kar->reg[reg1] >> 8 & 0xff;
			// vm->map[(ind + 3) % MEM_SIZE] = kar->reg[reg1] & 0xff;
		}
	}
	kar->pos = (kar->pos + step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
	return ;
}
