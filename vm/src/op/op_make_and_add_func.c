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
/*
** эта функция считывает аргументы определяет их тип
** и делает нужные с ними операции после чего записывает
** значения в фуфер. В случае если занчение регистра больше 16
** или меньше 16 записывает -1.
*/
void	read_args(t_vm *vm, t_kar *kar, uint32_t *args, uint8_t *cod_arg)
{
	int			i;
	int			j;
	int			n;
	uint16_t	ind;

	i = 0;
	j = 0;
	n = -1;
	while (++n < 3)
	{
		if (cod_arg[n] == REG_CODE)
		{
			if ((int)vm->map[(kar->pos + 2 + i) % MEM_SIZE] > 0 && (int)vm->map[(kar->pos + 2 + i) % MEM_SIZE] < 17)
				args[n] = vm->map[(kar->pos + 2 + i) % MEM_SIZE];
			else
				args[n] = -1;
			i += REG;
		}
		else if (cod_arg[n] == DIR_CODE)
		{
			args[n] = take_arg(vm, (kar->pos + 2 + i), 4);
			i += g_op[kar->op_id].dir_size;
		}
		else if (cod_arg[n] == IND_CODE)
		{
			ind = kar->pos + (short)take_arg(vm, (kar->pos + 2 + i), 2) % IDX_MOD;
			args[n] = take_arg(vm, (ind % MEM_SIZE), 4);
			i += IND;
		}
	}
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

//////////аналогичная функцыя к верхней ттолько из регистра в карту записываем
void	give_reg_to_map(t_vm *vm, int pos, int size_arg, uint32_t src)
{
	while (size_arg)
		vm->map[pos++ % MEM_SIZE] = src >> (8 * --size_arg) & 0xff;
}


// Функция которая отвечает за перемещение картеки
int step_for_not_valid(uint8_t *arg, t_kar *kar, int num_arg)
{
	int i;

	i = 0;
	while (--num_arg != -1)
	{
		if (arg[num_arg] == REG_CODE)
			i += REG;
		else if (arg[num_arg] == DIR_CODE)
			i += g_op[kar->op_id].dir_size;
		else if (arg[num_arg] == IND_CODE)
			i += IND;
	}
	i += (g_op[kar->op_id].is_args_types + 1);
	return (i);
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
		kar->cicles_to_wait = g_op[kar->op_id].wait;
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
