/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:53:19 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:53:21 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_and(t_vm *vm, t_kar *kar)
{
	uint8_t		arg[4]; // args_cods
	uint32_t	args[3]; // args_values
	int			i;
	int			start;

	i = 1;
	ft_bzero(arg, 4 * sizeof(uint8_t));
	ft_bzero(args, 2 * sizeof(uint8_t));
	check_argv_for_op(arg, vm, kar);
	while (arg[0] && arg[1] && arg[2] == REG_CODE && i--) // && !arg[3])
	{
		read_args(vm, kar, args, arg);
		if ((arg[0] == REG_CODE && (int)args[0] == -1) ||
			(arg[1] == REG_CODE && (int)args[0] == -1) ||
			(arg[2] == REG_CODE && (int)args[0] == -1))
		{
			kar->pos = (kar->pos + step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
			break ;
		}
		kar->reg[(int)args[2]] = args[0] & args[1];
		kar->carry = (!kar->reg[args[2]] ? 1 : 0);
		// OUTPUT V_FLAG = 4
		if (vm->v_fl == 4 || vm->v_fl == 30)
			ft_printf("P% 5d | and %d %d r%d\n", kar->id, args[0], args[1], (int)args[2]);
	}
	start = kar->pos;
	kar->pos = (kar->pos + step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;


	// OUTPUT V_FLAG = 16
	print_adv(vm, start, kar->pos);
}
