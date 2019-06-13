/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_make_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:28:28 by okuchko           #+#    #+#             */
/*   Updated: 2019/06/13 21:28:31 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			take_arg(t_vm *vm, int pos, int size_arg)
{
	int		arg;

	arg = 0;
	while (size_arg)
		arg += (vm->map[pos++ % MEM_SIZE] << (8 * --size_arg));
	return (arg);
}

static int	reg_add(uint8_t reg, uint32_t *args, int i, int n)
{
	if ((int)reg > 0 && (int)reg < 17)
		args[n] = reg;
	else
		args[n] = -1;
	i += REG;
	return (i);
}

void		read_args(t_vm *vm, t_kar *kar, uint32_t *args, uint8_t *cod_arg)
{
	int			i;
	int			n;
	uint16_t	ind;

	i = 0;
	n = -1;
	while (++n < 3)
	{
		if (cod_arg[n] == REG_CODE)
			i = reg_add(vm->map[(kar->pos + 2 + i) % MEM_SIZE], args, i, n);
		else if (cod_arg[n] == DIR_CODE)
		{
			args[n] = (g_op[kar->op_id].dir_size == 4 ?
						take_arg(vm, (kar->pos + 2 + i), 4) :
							(short)take_arg(vm, (kar->pos + 2 + i), 2));
			i += g_op[kar->op_id].dir_size;
		}
		else if (cod_arg[n] == IND_CODE)
		{
			ind = kar->pos +
					(short)take_arg(vm, (kar->pos + 2 + i), 2) % IDX_MOD;
			args[n] = take_arg(vm, (ind % MEM_SIZE), 4);
			i += IND;
		}
	}
}
