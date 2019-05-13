/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:20:13 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/03 16:58:35 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	if (haystack[i] == '\0' && needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		temp = i;
		while (needle[j] && haystack[i + j] && haystack[i + j]
									== needle[j] && i + j < len)
			j++;
		if (j == ft_strlen(needle))
			return ((char *)haystack + temp);
		i++;
	}
	return (NULL);
}
