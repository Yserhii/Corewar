/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:16:18 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/04 17:10:34 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(long long n)
{
	int			size;
	long long	nbr;

	size = 0;
	nbr = n;
	if (n == '\0')
		return (1);
	if (nbr < 0)
		size++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static long long	ft_abs(long long n)
{
	return (n < 0 ? -n : n);
}

char				*ft_itoa(long long n)
{
	int		size;
	char	*res;

	size = ft_size(n) - 1;
	if ((res = ft_strnew(ft_size(n))) != NULL)
	{
		if (n < 0)
			res[0] = 45;
		if (n == 0)
		{
			res[size] = '0';
			return (res);
		}
		while (n != 0)
		{
			res[size] = ft_abs(n % 10) + 48;
			n = n / 10;
			size--;
		}
		return (res);
	}
	return (NULL);
}
