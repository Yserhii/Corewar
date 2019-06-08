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
	int			dir;
	int			start;
	int			flag;

	flag = 0;
	start = kar->pos;
	dir = (short)take_arg(vm, (kar->pos + 1), 2);
	if (kar->carry && (flag = 1))
	{
		ft_printf("%hd\n", dir % IDX_MOD);
		kar->pos = (kar->pos + (dir % IDX_MOD)) % MEM_SIZE;
	}
	else
		kar->pos = (kar->pos + g_op[kar->op_id].dir_size + 1) % MEM_SIZE;
	if (vm->v_fl == 4 || vm->v_fl == 30)
		ft_printf("P% 5d | zjmp %d %s\n", kar->id, dir, flag ? "OK" : "FAILED");
	if (flag != 1)
		print_adv(vm, start, kar->pos);
}
