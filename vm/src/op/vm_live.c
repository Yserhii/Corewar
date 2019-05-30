/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:55:49 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/27 15:55:52 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_memrev(void *s, size_t len)
{
	size_t	i;
	char	*tmpmem;
	char	tmp;

	i = 0;
	tmpmem = (char *)s;
	while (i < len / 2)
	{
		tmp = tmpmem[i];
		tmpmem[i] = tmpmem[len - i - 1];
		tmpmem[len - i - 1] = tmp;
		i++;
	}
}

int		get_value(uint8_t *map, int start, int size)
{
	uint8_t	n[4];
	int		res;
	int		i;

	i = -1;
	ft_bzero(n, 4);
	while (++i < size)
		n[i + size % 4] = map[(start + i) % MEM_SIZE];
	if (n[2] >> 7 && size == 2)
	{
		n[0] = -1;
		n[1] = -1;
	}
	ft_memcpy(&res, n, 4);
	ft_memrev(&res, 4);
	return (res);
}

void	vm_live(t_vm *vm, t_kar *kar)
{
	int arg;

	arg = get_value(vm->map, (kar->pos + 1) % MEM_SIZE, g_op[kar->op_id - 1].dir_size);
	if (arg < 0)
		vm->last_say_live = abs(arg);
	vm->num_of_life++;
	kar->live = vm->cycles_from_start;
	(void)kar;
	(void)vm;
	return ;
}
