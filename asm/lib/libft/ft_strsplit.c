/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:34:28 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/04 15:02:57 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			res++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else if (s[i] == c)
			while (s[i] == c && s[i] != '\0')
				i++;
	}
	return (res);
}

static char	*ft_split(char *s, int res_j, char c, int i)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * res_j + 1);
	i = i - res_j;
	res_j = 0;
	while (s[i] != c && s[i] != '\0')
		res[res_j++] = s[i++];
	res[res_j] = '\0';
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		res_i;
	int		res_j;

	i = 0;
	res_i = 0;
	if (s == NULL)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * num_words(s, c) + 1)))
		return (NULL);
	while (res_i < num_words(s, c))
	{
		res_j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			res_j++;
			i++;
		}
		res[res_i++] = ft_split((char *)s, res_j, c, i);
	}
	res[res_i] = NULL;
	return (res);
}
