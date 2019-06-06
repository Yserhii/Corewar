/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:54:44 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:54:46 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_lldi(t_vm *vm, t_kar *kar)
{
	uint8_t		arg[4];
	uint32_t	args[3];
	uint32_t	ind;
	int			i;

	i = 1;
	ft_bzero(arg, 4 * sizeof(uint8_t));
	ft_bzero(args, 2 * sizeof(uint8_t));
	check_argv_for_op(arg, vm, kar);
	while (arg[0] && (arg[1] == REG_CODE || arg[1] == DIR_CODE) && arg[2] == REG_CODE && i--) // && !arg[3]
	{
		read_args(vm, kar, args, arg);
		if ((arg[0] == REG_CODE && (int)args[0] == -1) ||
			(arg[1] == REG_CODE && (int)args[1] == -1) ||
			(arg[2] == REG_CODE && (int)args[2] == -1))
			break;
		ind = kar->pos + (args[0] + args[1]);
		kar->reg[(int)args[2]] = take_arg(vm, (ind % MEM_SIZE), 4);
		kar->carry = (!kar->reg[args[2]] ? 1 : 0);
	}
	kar->pos = (kar->pos + step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
}
