/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:55:05 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 16:55:07 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_aff(t_vm *vm, t_kar *kar)
{
	uint8_t		kod[4]; /* args_cods */
	int			reg;
	char		c;
	// int			start;
/*
////Режим отображения вывода aff в оригинальном corewar
////В оригинальной виртуальной машине corewar по умолчанию
///режим отображения вывода операции aff выключен.
///Чтобы его включить нужно воспользоваться флагом -a.
/*/
	// start = kar->pos;
	ft_bzero(kod, 4 * sizeof(uint8_t));
	check_argv_for_op(kod, vm, kar);
	if (kod[0] == REG_CODE)/* && !kod[1] && !kod[2] && kod[3]*/
	{
		reg = kar->reg[vm->map[(kar->pos + 2) % MEM_SIZE]];
		if (reg > 0 && reg < 17)
		{
			c = kar->reg[reg] % 256;
			ft_printf("%c\n", c);
			if (vm->v_fl == 4 || vm->v_fl == 30)
				ft_printf("P% 5d | aff %d\n", kar->id,
								vm->map[(kar->pos + 2) % MEM_SIZE]);
		}
	}
	/* OUTPUT V_FLAG = 4*/
	// kar->pos = (kar->pos +
	// 		step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
	// print_adv(vm, start, kar->pos);
	print_adv(vm, kar->pos, kar->pos = (kar->pos + step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE);
}
