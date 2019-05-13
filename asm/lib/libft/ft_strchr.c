/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:30:19 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/15 16:08:03 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	size_t	i;

	i = ft_strlen(s);
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	if (s[i] == '\0' && c == '\0')
		return (temp);
	return (NULL);
}
