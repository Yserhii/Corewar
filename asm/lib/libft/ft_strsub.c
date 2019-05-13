/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:56:57 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/03 18:05:06 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		if ((str = (char *)malloc(sizeof(char) * len + 1)) != NULL)
		{
			while (i < len)
			{
				str[i] = s[start + i];
				i++;
			}
			str[i] = '\0';
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}
