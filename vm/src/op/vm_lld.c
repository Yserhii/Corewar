/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:54:30 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:54:34 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void static inline	vm_lld_add(t_vm *vm, t_kar *kar,
												uint8_t reg_size, uint32_t dir)
{
	kar->reg[(int)vm->map[kar->pos + reg_size]] = dir;
	kar->carry = (!kar->reg[(int)vm->map[kar->pos + reg_size]] ? 1 : 0);
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | lld %d r%d\n", kar->id, dir,
							vm->map[(kar->pos + reg_size) % MEM_SIZE]);
}

void				vm_lld(t_vm *vm, t_kar *kar)
{
	uint8_t		kod[4];
	uint8_t		reg_size;
	uint16_t	ind;
	uint32_t	dir;

	ft_bzero(kod, 4 * sizeof(uint8_t));
	check_argv_for_op(kod, vm, kar);
	if ((kod[0] == DIR_CODE || kod[0] == IND_CODE) && (kod[1] == REG_CODE))
	{
		if (kod[0] == DIR_CODE)
			dir = take_arg(vm, (kar->pos + 2), 4);
		else
		{
			ind = kar->pos + (short)take_arg(vm, (kar->pos + 2), 2);
			dir = take_arg(vm, (ind % MEM_SIZE), 4);
		}
		reg_size = (kod[0] == DIR_CODE ? 6 : 4);
		if ((int)vm->map[(kar->pos + reg_size) % MEM_SIZE] > 0 &&
						(int)vm->map[(kar->pos + reg_size) % MEM_SIZE] < 17)
			vm_lld_add(vm, kar, reg_size, dir);
	}
	print_adv(vm, kar->pos, kar->pos = (kar->pos +
		step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE);
}


////////////////////////////////////////////////////////////////////////////////////////////
// void	vm_lld(t_vm *vm, t_kar *kar)
// {
// 	uint8_t		kod[4];
// 	uint8_t		reg_size;
// 	uint16_t	ind;
// 	uint32_t	dir;
// 	// int			start;

// 	// start = kar->pos;
// 	ft_bzero(kod, 4 * sizeof(uint8_t));
// 	check_argv_for_op(kod, vm, kar);
// 	if ((kod[0] == DIR_CODE || kod[0] == IND_CODE) && (kod[1] == REG_CODE)) // && !kod[2] && !kod[3]) ?????? original ignors this args
// 	{
// 		if (kod[0] == DIR_CODE)
// 			dir = take_arg(vm, (kar->pos + 2), 4);
// 		else
// 		{
// 			ind = kar->pos + (short)take_arg(vm, (kar->pos + 2), 2);
// 			dir = take_arg(vm, (ind % MEM_SIZE), 4);
// 		}
// 		reg_size = (kod[0] == DIR_CODE ? 6 : 4);
// 		if ((int)vm->map[(kar->pos + reg_size) % MEM_SIZE] > 0 &&
// 						(int)vm->map[(kar->pos + reg_size) % MEM_SIZE] < 17)
// 		{
// 			kar->reg[(int)vm->map[kar->pos + reg_size]] = dir;
// 			kar->carry = (!kar->reg[(int)vm->map[kar->pos + reg_size]] ? 1 : 0);
// 			// OUTPUT V_FLAG = 4
// 			if (vm->v_fl == 4 || vm->v_fl == 30)
// 				ft_printf("P% 5d | lld %d r%d\n", kar->id, dir, vm->map[(kar->pos + reg_size) % MEM_SIZE]);
// 		}
// 	}
// 	// kar->pos = (kar->pos + step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
// 	// OUTPUT V_FLAG = 16
// 	// print_adv(vm, start, kar->pos);
// 	print_adv(vm, kar->pos, kar->pos = (kar->pos + step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE);
// }
