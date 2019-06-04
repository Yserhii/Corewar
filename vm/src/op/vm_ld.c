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
	uint8_t		reg;
	uint16_t	ind;
	uint32_t	dir;

	ft_bzero(arg, 4 * sizeof(uint8_t));
	check_argv_for_op(arg, vm, kar); // karetka na kode argumentov
	if ((arg[0] == DIR_CODE || arg[0] == IND_CODE) && (arg[1] == REG_CODE))// && !arg[2] && !arg[3]) ?????? original ignors this args
	{
		if (arg[0] == DIR_CODE)
			///////Здесь я заменил строчку ниже на новую адоптивную функции почитай над ней комент поймешь как работает!!!!!!!!!!
			dir = take_arg(vm, (kar->pos + 2), 4);
			// dir = (vm->map[(kar->pos + 2) % MEM_SIZE] << 24) + (vm->map[(kar->pos + 3) % MEM_SIZE] << 16) +
			// 	(vm->map[(kar->pos + 4) % MEM_SIZE] << 8) + vm->map[(kar->pos + 5) % MEM_SIZE];
		else
		{
			// ind = kar->pos + ((vm->map[(kar->pos + 2) % MEM_SIZE] << 8) + vm->map[(kar->pos + 3) % MEM_SIZE]) % IDX_MOD;
			// dir = (vm->map[ind % MEM_SIZE] << 24) + (vm->map[(ind + 1) % MEM_SIZE] << 16) + (vm->map[(ind + 2) % MEM_SIZE] << 8) + vm->map[(ind + 3) % MEM_SIZE];
			///////Здесь я заменил строчку ниже на новую адоптивную функции почитай над ней комент поймешь как работает!!!!!!!!!!
			ind = kar->pos + ((take_arg(vm, (kar->pos + 2), 2)) % IDX_MOD);
			///////Здесь я заменил строчку ниже на новую адоптивную функции почитай над ней комент поймешь как работает!!!!!!!!!!
			dir = take_arg(vm, (ind % MEM_SIZE), 4);
		}
		reg = (arg[0] == DIR_CODE ? 6 : 4);
		if (vm->map[(kar->pos + reg) % MEM_SIZE] >= 0x0 && vm->map[(kar->pos + reg) % MEM_SIZE] <= 0x16)
		{
			kar->reg[vm->map[kar->pos]] = dir;
			kar->carry = (!kar->reg[vm->map[kar->pos]] ? 1 : 0);
		}
	}
	///////Здесь я заменил строчку ниже на новую адоптивную функции почитай над ней комент поймешь как работает!!!!!!!!!!
	kar->pos = (kar->pos + step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
	// OUTPUT V_FLAG = 4
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | ld %d r%d\n", kar->id, arg, reg);
	return ;
}
