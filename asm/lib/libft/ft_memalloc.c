/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:19:17 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/13 14:51:46 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = (void *)malloc(sizeof(void) * size)) != NULL)
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
