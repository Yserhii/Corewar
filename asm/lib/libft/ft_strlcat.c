/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:45:34 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/03 17:03:42 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	j = 0;
	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (n == 0)
		return (s);
	if (n < d + 1)
		return (n + s);
	else
	{
		while (dst[i] && i < n - 1)
			i++;
		while (i + j < n - 1 && src[j])
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (d + s);
}
