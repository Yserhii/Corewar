/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:09:45 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:12:59 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	write_magic(char *data, int32_t pos, int32_t value, size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void	write_file(t_asm *head)
{
	int32_t	size;
	char	*res;

	size = 4;
	res = ft_strnew((size_t)size);
	write_magic(res, 0, COREWAR_EXEC_MAGIC, 4);
	write(head->fd_cor, res, (size_t)size);
	write(head->fd_cor, head->name, PROG_NAME_LENGTH);
	res = ft_memset(res, 0, 4);
	write(head->fd_cor, res, (size_t)size);
	write_magic(res, 0, head->b_pos, 4);
	write(head->fd_cor, res, 4);
	write(head->fd_cor, head->comment, COMMENT_LENGTH);
	res = ft_memset(res, 0, 4);
	write(head->fd_cor, res, (size_t)size);
	free(res);
}
