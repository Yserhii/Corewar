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

static void	check_magic_header(t_bot *bot)
{
	uint32_t	mh;

	mh = (bot->all_info[0] << 24) + (bot->all_info[1] << 16) +
						(bot->all_info[2] << 8) + bot->all_info[3];
	if (COREWAR_EXEC_MAGIC != mh)
		vm_exit_bot(6, bot);
}

static void	check_and_record_name(t_bot *bot)
{
	uint32_t	i;
	uint32_t	j;
	int			flag;

	i = 3;
	j = -1;
	flag = 0;
	while (++i < 132)
	{
		if (!bot->all_info[i] && !flag)
			flag++;
		else if (bot->all_info[i] && flag)
			vm_exit_bot(5, bot);
		bot->name[++j] = bot->all_info[i];
	}
}

static void	check_null_and_size(t_bot *bot)
{
	uint32_t	i;
	uint32_t	j;
	uint8_t		*str;

	str = bot->all_info;
	if ((i = (str[132] << 24) + (str[133] << 16) + (str[134] << 8) + str[135]))
		vm_exit_bot(3, bot);
	if ((j = (str[2188] << 24) + (str[2189] << 16) +
												(str[2190] << 8) + str[2191]))
		vm_exit_bot(3, bot);
	if ((bot->size = (str[136] << 24) + (str[137] << 16) +
					(str[138] << 8) + str[139]) && (bot->size > CHAMP_MAX_SIZE))
		vm_exit_bot(4, bot);
	if (bot->size < 1)
		vm_exit_bot(4, bot);
}

static void	check_and_record_comment(t_bot *bot)
{
	uint32_t	i;
	uint32_t	j;
	int			flag1;

	i = 139;
	j = -1;
	flag1 = 0;
	while (++i < 2188)
	{
		if (!bot->all_info[i] && !flag1)
			flag1++;
		else if (bot->all_info[i] && flag1)
			vm_exit_bot(2, bot);
		bot->comment[++j] = bot->all_info[i];
	}
}

static void	check_and_record_exec_code(t_bot *bot)
{
	uint32_t	i;
	uint32_t	j;

	i = 2191;
	j = -1;
	if (!(bot->code = (uint8_t*)ft_memalloc(sizeof(uint8_t) * (bot->size + 1))))
		vm_exit(9);
	while (++i < 2192 + bot->size)
		bot->code[++j] = bot->all_info[i];
	while (++i < 5000)
		if (bot->all_info[i] || 2192 + bot->size != bot->size_read)
			vm_exit_bot(1, bot);
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
