/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:01:33 by yserhii           #+#    #+#             */
/*   Updated: 2019/04/23 13:01:34 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_allnum(char *str)
{
	if (!str)
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (!*str)
		return (1);
	else
		return (0);
}
