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


//// эта функцыя в зависимости от размера аргумента считывает по нужному
//// указателю карту и запысывает это в инт например для
//// Дир size_arg = 4 , а для Инт size_arg = 2
//// pos это точный казатель с которого начинает после чего шагает
int		take_arg(t_vm *vm, int pos, int size_arg)
{
	int		arg;

	arg = 0;
	while (size_arg)
		arg += (vm->map[pos++ % MEM_SIZE] << (8 * --size_arg));
	return (arg);
}

void	check_argv_for_op(uint8_t *arg, t_vm *vm, t_kar *kar)
{
	arg[0] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 6 & 0x3);
	arg[1] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 4 & 0x3);
	arg[2] = (vm->map[(kar->pos + 1) % MEM_SIZE] >> 2 & 0x3);
	arg[3] = (vm->map[(kar->pos + 1) % MEM_SIZE] & 0x3);
}

void	op_recognize(t_vm *vm, t_kar *kar)
{
	// ft_printf("op_recognize: ");
	if (vm->map[kar->pos] >= 0x01 && vm->map[kar->pos] <= 0x10)
	{
		kar->op_id = vm->map[kar->pos];
		kar->cicles_to_wait = g_op[kar->op_id - 1].wait;
		// ft_printf("%d\n", kar->cicles_to_wait);
		// ft_printf("OK op_id: %d position: %d\n",kar->op_id, kar->pos);
	}
	else
	{	// if opration code is incorrect
		kar->op_id = vm->map[kar->pos];
		kar->pos++; // Yes we need it
		kar->cicles_to_wait = 0;
		// ft_printf("incorrect op_id: %d position: %d\n",kar->op_id, kar->pos);
	}
}
