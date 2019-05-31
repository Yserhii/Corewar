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

// void	ft_memrev(void *s, size_t len)
// {
// 	size_t	i;
// 	char	*tmpmem;
// 	char	tmp;

// 	i = 0;
// 	tmpmem = (char *)s;
// 	while (i < len / 2)
// 	{
// 		tmp = tmpmem[i];
// 		tmpmem[i] = tmpmem[len - i - 1];
// 		tmpmem[len - i - 1] = tmp;
// 		i++;
// 	}
// }

// int		get_arg_live(uint8_t *map, int start, int size)
// {
	// // int		res;
	// // int		i;
	// // uint8_t	n[4];

	// // i = -1;
	// // ft_bzero(n, 4);
	// // while (++i < size)
	// // 	n[i + size % 4] = map[(start + i) % MEM_SIZE];
	// // if (n[2] >> 7 && size == 2)
	// // {
	// // 	n[0] = -1;
	// // 	n[1] = -1;
	// // }
	// // ft_memcpy(&res, n, 4);
	// // ft_memrev(&res, 4);
	// int		num_bot;

	// num_bot = map[(start) % MEM_SIZE];
	// return (num_bot);
	// // return (res);
// }

void	vm_live(t_vm *vm, t_kar *kar)
{
	int		arg;

	kar->pos += g_op[kar->op_id].is_args_types;
	// arg = get_arg_live(vm->map, (kar->pos + 1) % MEM_SIZE, g_op[kar->op_id - 1].dir_size);
	arg = vm->map[(g_op[kar->op_id].is_args_types + 1) % MEM_SIZE];
	if ((int)kar->bot_id == arg)
	{
		vm->last_say_live = kar->bot_id;
		kar->live = vm->cycles_from_start;
	}
	vm->num_of_life++; //вне цыкла;
	kar->pos += g_op[kar->op_id].dir_size;
	return ;
}
