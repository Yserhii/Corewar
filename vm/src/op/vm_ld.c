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

int		step_for_not_valid(uint8_t *arg, t_kar *kar)
{
	int i;

	i = 0;
	if (arg[0] == REG_CODE || arg[1] == REG_CODE)
		i += REG;
	if (arg[0] == DIR_CODE || arg[1] == DIR_CODE)
		i += g_op[kar->op_id].dir_size;
	if (arg[0] == IND_CODE || arg[1] == IND_CODE)
		i += IND;
	i += 1;
	return (i);
}

void	vm_ld(t_vm *vm, t_kar *kar)
{
	uint8_t		arg[4];
	uint16_t	ind;
	uint32_t	dir;

	ft_bzero(arg, 4 * sizeof(uint8_t));
	kar->pos = check_argv_for_op(arg, vm, kar); // karetka na kode argumentov
	if ((arg[0] == DIR_CODE || arg[0] == IND_CODE) && (arg[1] == REG_CODE))// && !arg[2] && !arg[3]) ?????? original ignors this args
	{
		if (arg[0] == DIR_CODE)
			dir = (vm->map[(kar->pos + 1) % MEM_SIZE] << 24) +
				(vm->map[(kar->pos + 2) % MEM_SIZE] << 16) +
				(vm->map[(kar->pos + 3) % MEM_SIZE] << 8) +
				vm->map[(kar->pos + 4) % MEM_SIZE];
		else
		{
			ind = (vm->map[(kar->pos + 1) % MEM_SIZE] << 8) + vm->map[(kar->pos + 2) % MEM_SIZE];
			ind = ++kar->pos + ind % IDX_MOD;
			dir = (vm->map[ind % MEM_SIZE] << 24) + (vm->map[(ind + 1) % MEM_SIZE] << 16) + (vm->map[(ind + 2) % MEM_SIZE] << 8) + vm->map[(ind + 3) % MEM_SIZE];
		}
		kar->pos += (arg[0] == DIR_CODE ? g_op[kar->op_id].dir_size + g_op[kar->op_id].is_args_types : IND);
		if (vm->map[kar->pos] >= 0x0 && vm->map[kar->pos] <= 0x16)
		{
			kar->reg[vm->map[kar->pos]] = dir;
			kar->carry = (!kar->reg[vm->map[kar->pos]] ? 1 : 0);
		}
		kar->pos += REG;
	}
	else
		kar->pos = (kar->pos + step_for_not_valid(arg, kar)) % MEM_SIZE;
	return ;
}
