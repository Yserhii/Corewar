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

void	read_bot_and_id(t_vm *vm)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	vm->bot = ft_memalloc(vm->num_bot + 1);
	while (++i < vm->num_bot)
	{
		vm->bot[i] = ft_memalloc(sizeof(t_bot));
		vm->bot[i]->all_info = ft_memalloc(sizeof(unsigned char) * 5000);
		while (++j < 4 && !vm->fd[j]);
		if (j < 4 && read(vm->fd[j], vm->bot[i]->all_info, 5000) > 0)
			vm->bot[i]->id = j + 1;
		else
			exit(ft_printf("{red}Can't read file with bot{eoc}\n"));
	}
}


void	check_magic_header(t_bot *bot)
{
	uint32_t	mh;

	mh = (bot->all_info[1] << 16) + (bot->all_info[2] << 8) + bot->all_info[3];
	if (COREWAR_EXEC_MAGIC != mh)
		exit(ft_printf("{red}Invalid magic header, bot id = [%d]{eoc}\n", bot->id));
}

void	check_and_record_name(t_bot *bot)
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
			exit(ft_printf("{red}Invalid name, bot id = [%d]{eoc}\n", bot->id));
		bot->name[++j] = (char)bot->all_info[i];
	}
	ft_printf("%s\n", bot->name);//////удалить после
}

void	check_null_and_size(t_bot *bot)
{
	uint32_t	i;
	uint32_t	j;
	uint8_t		*str;

	str = bot->all_info;
	if	((i = (str[132] << 24) + (str[133] << 16) + (str[134] << 8) + str[135]))
			exit(ft_printf("{red}Not NULL after name bot, bot id = [%d]{eoc}\n", bot->id));
	if	((j = (str[2188] << 24) + (str[2189] << 16) + (str[2190] << 8) + str[2191]))
			exit(ft_printf("{red}Not NULL after name bot, bot id = [%d]{eoc}\n", bot->id));
	if	(!(bot->size = (str[136] << 24) + (str[137] << 16) + (str[138] << 8) + str[139]) || (bot->size > CHAMP_MAX_SIZE))
			exit(ft_printf("{red}Exec code not valid size = [%d], bot id = [%d]{eoc}\n", bot->size, bot->id));
	ft_printf("%d\n", bot->size);//////удалить после
}

void	check_and_record_comment(t_bot *bot)
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
			exit(ft_printf("{red}Invalid commet, bot id = [%d]{eoc}\n", bot->id));
		bot->comment[++j] = (char)bot->all_info[i];
		ft_printf("%c", bot->comment[j]);//////удалить после
	}
}

void	check_and_record_exec_code(t_bot *bot)
{
	uint32_t	i;
	uint32_t	j;

	i = 2191;
	j = -1;
	while (++i < 2191 + bot->size)
		bot->comment[++j] = (char)bot->all_info[i];
	while(++i < 5000)
		if ((char)bot->all_info[i])
			exit(ft_printf("{red}Exec code differs from his size, bot id = [%d]{eoc}\n", bot->id));
}

void	read_valid_bot(t_vm *vm)
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
