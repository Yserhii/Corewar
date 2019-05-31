/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_make_and_add_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:02:22 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/28 13:02:25 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	valid_op_arg(t_vm *vm, t_kar *kar)
{
	(void)vm;
	(void)kar;
}

void	op_recognize(t_vm *vm, t_kar *kar)
{
	ft_printf("op_recognize: ");
	if (vm->map[kar->pos] >= 0x01 && vm->map[kar->pos] <= 0x10)
	{
		kar->op_id = vm->map[kar->pos];
		kar->cicles_to_wait = g_op[kar->op_id - 1].wait;
		// ft_printf("%d\n", kar->cicles_to_wait);
		ft_printf("OK op_id: %d position: %d\n",kar->op_id, kar->pos);
	}
	else
	{	// if opration code is incorrect
		kar->op_id = vm->map[kar->pos];
		kar->pos++; // Yes we need it
		kar->cicles_to_wait = 0;
		ft_printf("incorrect op_id: %d position: %d\n",kar->op_id, kar->pos);
	}
}




	// if (vm->map[kar->op_id] == 0x01)
	// 	vm_live(vm, kar);
	// else if (vm->map[kar->op_id] == 0x02)
	// 	vm_ld(vm, kar);
	// else if (vm->map[kar->op_id] == 0x03)
	// 	vm_st(vm, kar);
	// else if (vm->map[kar->op_id] == 0x04)
	// 	vm_add(vm, kar);
	// else if (vm->map[kar->op_id] == 0x05)
	// 	vm_sub(vm, kar);
	// else if (vm->map[kar->op_id] == 0x06)
	// 	vm_and(vm, kar);
	// else if (vm->map[kar->op_id] == 0x07)
	// 	vm_or(vm, kar);
	// else if (vm->map[kar->op_id] == 0x08)
	// 	vm_xor(vm, kar);
	// else if (vm->map[kar->op_id] == 0x09)
	// 	vm_zjmp(vm, kar);
	// else if (vm->map[kar->op_id] == 0x0a)
	// 	vm_ldi(vm, kar);
	// else if (vm->map[kar->op_id] == 0x0b)
	// 	vm_sti(vm, kar);
	// else if (vm->map[kar->op_id] == 0x0c)
	// 	vm_fork(vm, kar);
	// else if (vm->map[kar->op_id] == 0x0d)
	// 	vm_lld(vm, kar);
	// else if (vm->map[kar->op_id] == 0x0e)
	// 	vm_lldi(vm, kar);
	// else if (vm->map[kar->op_id] == 0x0f)
	// 	vm_lfork(vm, kar);
	// else if (vm->map[kar->op_id] == 0x10)
	// 	vm_aff(vm, kar);
