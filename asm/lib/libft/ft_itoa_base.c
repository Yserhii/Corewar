/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:19:00 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 16:57:33 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned long long int n, int base)
{
	int						size;
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

char		*ft_itoa_base(unsigned long long int n, int base)
{
	int		size;
	char	*res;

	size = ft_size(n, base) - 1;
	if ((res = ft_strnew(ft_size(n, 8))) != NULL)
	{
		if (n == 0)
		{
			res[0] = n + 48;
			return (res);
		}
		while (n != 0)
		{
			res[size] = (n % base) + 48;
			n = n / base;
			size--;
		}
		return (res);
	}
	return (NULL);
}
