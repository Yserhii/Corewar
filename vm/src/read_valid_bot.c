/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid_bot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:09:29 by yserhii           #+#    #+#             */
/*   Updated: 2019/05/16 18:09:31 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	read_bot_and_id(t_vm *vm)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	if (!(vm->bot = (t_bot**)ft_memalloc(sizeof(t_bot*) * (vm->num_bot + 1))))
		vm_exit(9);
	while (++i < vm->num_bot)
	{
		if (!(vm->bot[i] = (t_bot*)ft_memalloc(sizeof(t_bot))))
			vm_exit(9);
		if (!(vm->bot[i]->all_info =
								(uint8_t*)ft_memalloc(sizeof(uint8_t) * 5000)))
			vm_exit(9);
		while (++j < 4 && !vm->fd[j])
			;
		vm->bot[i]->size_read = read(vm->fd[j], vm->bot[i]->all_info, 5000);
		if (j < 4 && vm->bot[i]->size_read > 0 && vm->bot[i]->size_read < 5000)
			vm->bot[i]->id = j + 1;
		else
			vm_exit(10);
	}
}

void		read_valid_bot(t_vm *vm)
{
	int		num_bot;

	num_bot = -1;
	read_bot_and_id(vm);
	while (++num_bot < vm->num_bot)
	{
		check_magic_header(vm->bot[num_bot]);
		check_and_record_name(vm->bot[num_bot]);
		check_null_and_size(vm->bot[num_bot]);
		check_and_record_comment(vm->bot[num_bot]);
		check_and_record_exec_code(vm->bot[num_bot]);
		free(vm->bot[num_bot]->all_info);
	}
}
