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

void	write_magic(int32_t pos, int32_t value,size_t size, t_asm *head)
{
	int8_t		i;
	char		*data;

	i = 0;
	data = ft_strnew(4);
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}
