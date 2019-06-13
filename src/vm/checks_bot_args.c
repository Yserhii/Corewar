/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bot_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:28:02 by okuchko           #+#    #+#             */
/*   Updated: 2019/06/13 21:28:04 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	check_magic_header(t_bot *bot)
{
	uint32_t	mh;

	mh = (bot->all_info[0] << 24) + (bot->all_info[1] << 16) +
						(bot->all_info[2] << 8) + bot->all_info[3];
	if (COREWAR_EXEC_MAGIC != mh)
		vm_exit_bot(6, bot);
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
			vm_exit_bot(5, bot);
		bot->name[++j] = bot->all_info[i];
	}
}

void	check_null_and_size(t_bot *bot)
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
			vm_exit_bot(2, bot);
		bot->comment[++j] = bot->all_info[i];
	}
}

void	check_and_record_exec_code(t_bot *bot)
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
