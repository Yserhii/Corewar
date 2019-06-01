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

static inline int		step_for_not_valid(uint8_t *arg, t_kar *kar)
{
	int		i;

	i = 0;
	if (arg[0] == REG_CODE || arg[1] == REG_CODE)
		i += REG;
	if (arg[0] == DIR_CODE || arg[1] == DIR_CODE)
		i += g_op[kar->op_id].dir_size;
	if (arg[0] == IND_CODE || arg[1] == IND_CODE)
		i += IND;
	i += 1 + g_op[kar->op_id].is_args_types;
	return (i);
}

void	vm_st(t_vm *vm, t_kar *kar)
{
	uint8_t		arg[4];
	uint16_t	ind;
	uint8_t		reg1;
	uint8_t		reg2;

	ft_bzero(arg, 4);
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
			ind = kar->pos + ((take_arg(vm, (kar->pos + 3), 2)) % IDX_MOD);
			vm->map[(ind) % MEM_SIZE] = kar->reg[reg1] >> 24;
			vm->map[(ind + 1) % MEM_SIZE] = kar->reg[reg1] >> 16;
			vm->map[(ind + 2) % MEM_SIZE] = kar->reg[reg1] >> 8;
			vm->map[(ind + 3) % MEM_SIZE] = kar->reg[reg1];
		}
	}
	kar->pos = (kar->pos + step_for_not_valid(arg, kar)) % MEM_SIZE;
	return ;
}
