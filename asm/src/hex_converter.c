/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:13:07 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:13:13 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	hex_con(int32_t nbr, int size, t_asm *head)
{
	unsigned int	tmp;
	int				i;
	// int				j;
	unsigned int	max;
	char			*res;

	if (size == 1)
		max = 255;
	if (size == 2)
		max = 65535;
	if (size == 4)
		max = 4294967295;
	if (nbr < 0)
		tmp = max + nbr + 1;
	else
		tmp = nbr;
	res = ft_memalloc(sizeof(char) * size);
	i = size + head->pos;
	// j = head->pos + size;
	while (--i >= head->pos)
	{
		head->code[i] = tmp % 256;
		tmp /= 256;
		// j--;
		// res[i] = tmp % 256;
		// tmp /= 256;
	}
	head->pos += size;
	// while (i < size)
	// {
	// 	head->code[head->pos] = res[i];
	// 	i++;
	// 	head->pos++;
	// }
	// head->code = ft_strjoin(head->code, res);
	// exit (1);
	write(head->fd_cor, head->code, size);
	free(res);
}
