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
	uint8_t		kod[4];
	int			reg;
	char		c;

	ft_bzero(kod, 4 * sizeof(uint8_t));
	check_argv_for_op(kod, vm, kar);
	if (kod[0] == REG_CODE && vm->a_fl)
	{
		reg = (int)vm->map[(kar->pos + 2) % MEM_SIZE];
		if (reg > 0 && reg < 17)
		{
			c = kar->reg[reg] % 256;
			ft_printf("Aff: %c\n", c);
		}
	}
	print_adv(vm, kar->pos,
		kar->pos += step_for_not_valid(kod, kar, g_op[kar->op_id].num_arg));
}
