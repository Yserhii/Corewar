/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:09:45 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/13 18:09:46 by yhliboch         ###   ########.fr       */
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
	int32_t	i;
	char	*res;

	i = 0;
	size = 4;
	res = ft_strnew((size_t)size);
	write_magic(res, i, COREWAR_EXEC_MAGIC, 4);
	write(head->fd_cor, res, (size_t)size);
	write(head->fd_cor, head->name, PROG_NAME_LENGTH);
	res = ft_memset(res, 0, 4);
	write(head->fd_cor, res, (size_t)size);
	// i += PROG_NAME_LENGTH;
	// i += 4;
	i = 0;
	write_magic(res, i, head->b_pos, 4);
	write(head->fd_cor, res, 4);
	// i += 4;
	// i += 4;
	write(head->fd_cor, head->comment, COMMENT_LENGTH);
	res = ft_memset(res, 0, 4);
	write(head->fd_cor, res, (size_t)size);
	// i += COMMENT_LENGTH;
	// i += 4;
	// printf("[%ss]\n", head->hex_code);
	// ft_memcpy(&res[i], head->hex_code, 7);
	// write(head->fd_cor, res, (size_t)size);
	free(res);


	// i = 0;
	// size = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + 7;
	// res = ft_strnew((size_t)size);
	// write_magic(res, i, COREWAR_EXEC_MAGIC, 4);
	// i += 4;
	// ft_memcpy(&res[i], head->name, ft_strlen(head->name));
	// i += PROG_NAME_LENGTH;
	// i += 4;
	// write_magic(res, i, head->b_pos, 4);
	// // i += 4;
	// i += 4;
	// ft_memcpy(&res[i], head->comment, ft_strlen(head->comment));
	// i += COMMENT_LENGTH;
	// i += 4;
	// printf("[%s]\n", head->hex_code);
	// ft_memcpy(&res[i], head->hex_code, 7);
	// write(head->fd_cor, res, (size_t)size);
	// free(res);
}
