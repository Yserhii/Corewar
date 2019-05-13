/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:37:13 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/08 12:02:57 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			return (dst + i + 1);
		}
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (NULL);
}
