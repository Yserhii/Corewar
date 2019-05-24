/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:15:49 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 14:15:51 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

static int	num_words(char const *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '	' && s[i] != '\0')
		{
			res++;
			while (s[i] != ' ' && s[i] != '	' && s[i] != '\0')
				i++;
		}
		else if (s[i] == ' ' || s[i] == '	')
			while ((s[i] == ' ' || s[i] == '	') && s[i] != '\0')
				i++;
	}
	return (res);
}

static char	*ft_split(char *s, int res_j, int i)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * res_j + 1);
	i = i - res_j;
	res_j = 0;
	while (s[i] != ' ' && s[i] != '	' && s[i] != '\0')
		res[res_j++] = s[i++];
	res[res_j] = '\0';
	return (res);
}

char		**ft_strsplit_tokens(char const *s)
{
	char	**res;
	int		i;
	int		res_i;
	int		res_j;

	i = 0;
	res_i = 0;
	if (s == NULL)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * num_words(s) + 1)))
		return (NULL);
	while (res_i < num_words(s))
	{
		res_j = 0;
		while (s[i] == ' ' || s[i] == '	')
			i++;
		while (s[i] != ' ' && s[i] != '	' && s[i] != '\0')
		{
			res_j++;
			i++;
		}
		res[res_i++] = ft_split((char *)s, res_j, i);
	}
	res[res_i] = NULL;
	return (res);
}
