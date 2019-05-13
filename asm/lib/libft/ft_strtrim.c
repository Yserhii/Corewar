/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 11:17:07 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/09 18:04:55 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char *str, char *s, size_t i, size_t j)
{
	size_t str_i;

	str_i = 0;
	while (i <= j)
		str[str_i++] = s[i++];
	str[str_i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	temp;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	while (s[j] == '\0' || s[j] == '\n' || s[j] == ' ' || s[j] == '\t')
		j--;
	temp = ft_strlen(s) - j - 1;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i - temp) + 1)))
		return (NULL);
	str = ft_trim(str, (char *)s, i, j);
	return (str);
}
