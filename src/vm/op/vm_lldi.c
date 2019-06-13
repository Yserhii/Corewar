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

void static inline	v_fl_4_30(t_kar *kar, uint32_t *args, uint32_t ind)
{
	ft_printf("P% 5d | lldi %d %d r%d\n", kar->id, (int)args[0],
		(int)args[1], (int)args[2]);
	ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
		(int)args[0], (int)args[1], (int)((int)args[0] + (int)args[1]), ind);
}

void				vm_lldi(t_vm *vm, t_kar *kar)
{
	uint8_t		kod[4];
	uint32_t	args[3];
	uint32_t	ind;
	int			i;

	i = -1;
	ft_bzero(kod, 4 * sizeof(uint8_t));
	ft_bzero(args, 3 * sizeof(uint8_t));
	check_argv_for_op(kod, vm, kar);
	if (kod[0] && (kod[1] == REG_CODE || kod[1] == DIR_CODE) && kod[2] == 1)
	{
		read_args(vm, kar, args, kod);
		if (!((kod[0] == REG_CODE && (int)args[0] == -1) || (kod[1] == REG_CODE
		&& (int)args[1] == -1) || (kod[2] == REG_CODE && (int)args[2] == -1)))
		{
			while (++i < 2)
				kod[i] == REG_CODE ? args[i] = kar->reg[(int)args[i]] : 0;
			ind = kar->pos + (int)args[0] + (int)args[1];
			kar->reg[(int)args[2]] = take_arg(vm, (ind % MEM_SIZE), 4);
			kar->carry = (!kar->reg[args[2]] ? 1 : 0);
			(vm->v_fl == 4 || vm->v_fl == 30) ? v_fl_4_30(kar, args, ind) : 0;
		}
	}
	print_adv(vm, kar->pos,
		kar->pos += step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg));
}
