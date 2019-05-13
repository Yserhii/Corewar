/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:24:04 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/03 16:55:52 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	if (haystack[i] == '\0' && needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		temp = i;
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (j == ft_strlen(needle))
			return ((char *)haystack + temp);
		i++;
	}
	return (NULL);
}
