/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:40:31 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/12 12:40:34 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_words(char *str, int sep)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		num++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (num);
}
