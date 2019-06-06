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
	uint8_t		arg[4]; // args_cods
	int			reg;
	char		c;
///
////Режим отображения вывода aff в оригинальном corewar
////В оригинальной виртуальной машине corewar по умолчанию
///режим отображения вывода операции aff выключен.
///Чтобы его включить нужно воспользоваться флагом -a.
///
	ft_bzero(arg, 4 * sizeof(uint8_t));
	check_argv_for_op(arg, vm, kar);
	if (arg[0] == REG_CODE)// && !arg[1] && !arg[2] && arg[3]
	{
		reg = kar->reg[vm->map[(kar->pos + 2) % MEM_SIZE]];
		c = kar->reg[reg] % 256;
		ft_printf("%c\n", c);
	}
	kar->pos = (kar->pos + step_for_not_valid(arg, kar, g_op[kar->op_id].num_arg)) % MEM_SIZE;
}
