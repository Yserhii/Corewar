/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:51:30 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/03 17:48:02 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	i;
	int					true_false;

	i = 0;
	true_false = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			true_false = 0;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		i = i * 10 + *str - 48;
		if (i >= 9223372036854775807 && true_false == 1)
			return (-1);
		else if (i > 9223372036854775807 && true_false == 0)
			return (0);
		str++;
	}
	return (true_false ? i : -i);
}
