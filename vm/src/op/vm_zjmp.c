/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:53:46 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:53:49 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_zjmp(t_vm *vm, t_kar *kar)
{
	uint8_t		kod[4];
	int			dir;
	int			start;
	int			flag;

	flag = 0;
	start = kar->pos;
	check_argv_for_op(kod, vm, kar);
	if (kod[0] == DIR_CODE && kar->carry && (flag = 1)) // !kod[1] && !kod[2] && !kod[3]
		dir = (int)take_arg(vm, (kar->pos + 2), 2);
	if (kar->carry)
		kar->pos = (kar->pos + (dir % IDX_MOD)) % MEM_SIZE;
	else
		kar->pos = (kar->pos + step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | zjmp %d %s\n", kar->id, vm->map[(start + 2) % MEM_SIZE], flag ? "SUCCESS" : "FAILED");
	print_adv(vm, start, kar->pos);
}
