/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:53:54 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:53:56 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_ldi(t_vm *vm, t_kar *kar)
{
	uint8_t		kod[4];
	uint32_t	args[3];
	uint32_t	ind;
	int			i;
	// int			start;

	i = -1;
	// start = kar->pos;
	ft_bzero(kod, 4 * sizeof(uint8_t));
	ft_bzero(args, 3 * sizeof(uint8_t));
	check_argv_for_op(kod, vm, kar);
	if (kod[0] && (kod[1] == REG_CODE || kod[1] == DIR_CODE) && kod[2] == REG_CODE) // && !kod[3]
	{
		read_args(vm, kar, args, kod);
		if (!((kod[0] == REG_CODE && (int)args[0] == -1) ||
				(kod[1] == REG_CODE && (int)args[1] == -1) ||
					(kod[2] == REG_CODE && (int)args[2] == -1)))
		{
			while (++i < 2)
				if (kod[i] == REG_CODE)
					args[i] = kar->reg[(int)args[i]];
			ind = kar->pos + (int)((int)args[0] + (int)args[1]) % IDX_MOD;
			kar->reg[(int)args[2]] = take_arg(vm, (ind % MEM_SIZE), 4);
			// OUTPUT V_FLAG = 4
			if (vm->v_fl == 4 || vm->v_fl == 30)
			{
				ft_printf("P% 5d | ldi %d %d r%d\n", kar->id, args[0], args[1], (int)args[2]);
				ft_printf("       | load from %d + %d = %d (with pc and mod \?\?\?)\n", args[0], args[1], args[0] + args[1]);
			}
		}
	}
	// kar->pos = (kar->pos + step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
	// print_adv(vm, start, kar->pos);
	print_adv(vm, kar->pos, kar->pos = (kar->pos + step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE);
}
