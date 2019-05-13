/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:45:06 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 16:58:01 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	ft_size(unsigned int long long n, int base)
{
	unsigned long long int	size;
	unsigned long long int	nbr;

	size = 0;
	nbr = n;
	if (n == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / base;
		size++;
	}
	return (size);
}

char							*ft_itoa_x(unsigned long long int n, t_mod *md)
{
	unsigned int	size;
	char			*res;
	char			c;

	c = (md->x == 1 ? 'A' : 'a');
	size = ft_size(n, 16) - 1;
	if ((res = ft_strnew(ft_size(n, 16))) != NULL)
	{
		if (n == 0)
		{
			res[size] = '0';
			return (res);
		}
		while (n > 0)
		{
			res[size] = (n % 16) + (n % 16 >= 10 ? c - 10 : 48);
			n = n / 16;
			size--;
		}
		return (res);
	}
	return (NULL);
}
