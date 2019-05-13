/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:14:38 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 16:57:48 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_zero(char **res, int size)
{
	int		i;
	int		j;
	char	*res1;

	i = ft_strlen(*res);
	j = 0;
	res1 = *res;
	size -= (int)ft_strlen(*res);
	while (j < size)
	{
		res1[i + j] = '0';
		j++;
	}
}

char		*ft_itoa_f(long double n)
{
	long double	point;
	long double	temp;
	long long	size;
	char		*res;
	int			i;

	i = 0;
	temp = n;
	point = 1;
	size = 1;
	while (temp >= 10 && (point *= 10) && (size++) && size <= 18)
		temp /= 10;
	res = ft_strnew(size);
	if ((long long)temp == 0)
		res[0] = '0';
	while (n >= 1 && (temp = n) && i <= size)
	{
		temp /= point;
		res[i] = (long long)temp + 48;
		n -= (long long)temp * point;
		point /= 10;
		i++;
	}
	check_zero(&res, size);
	return (res);
}
