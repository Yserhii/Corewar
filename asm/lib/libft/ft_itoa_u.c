/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:21:58 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 16:57:54 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_size(unsigned long long int n)
{
	unsigned int			size;
	unsigned long long int	nbr;

	size = 0;
	nbr = n;
	if (n == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

char				*ft_itoa_u(unsigned long long int n)
{
	unsigned int	size;
	char			*res;

	size = ft_size(n) - 1;
	if ((res = ft_strnew(ft_size(n))) != NULL)
	{
		if (n == 0)
		{
			res[0] = n + 48;
			return (res);
		}
		while (n != 0)
		{
			res[size] = (n % 10) + 48;
			n = n / 10;
			size--;
		}
		return (res);
	}
	return (NULL);
}
