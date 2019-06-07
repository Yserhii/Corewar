/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:53:36 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:53:38 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_xor(t_vm *vm, t_kar *kar)
{
	uint8_t		kod[4];   // args_cods
	uint32_t	args[3]; // args_values
	int			start;
	int i;

	i = -1;
	start = kar->pos;
	ft_bzero(kod, 4 * sizeof(uint8_t));
	ft_bzero(args, 2 * sizeof(uint8_t));
	check_argv_for_op(kod, vm, kar);
	if (kod[0] && kod[1] && kod[2] == REG_CODE) // && !arg[3])
	{
		read_args(vm, kar, args, kod);
		if (!((kod[0] == REG_CODE && (int)args[0] == -1) ||
				(kod[1] == REG_CODE && (int)args[1] == -1) ||
					(kod[2] == REG_CODE && (int)args[2] == -1)))
		{
			while (++i < 2)
				if (kod[i] == REG_CODE)
					args[i] = kar->reg[args[i]];
			kar->reg[args[2]] = args[0] ^ args[1];
			kar->carry = (!kar->reg[args[2]] ? 1 : 0);
			// OUTPUT V_FLAG = 4
			if (vm->v_fl == 4 || vm->v_fl == 30)
				ft_printf("P% 5d | xor %d %d r%d\n", kar->id, args[0], args[1], (int)args[2]);
		}
	}
	print_adv(vm, kar->pos, (kar->pos = kar->pos + step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE);
}
