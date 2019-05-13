/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:48:14 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/03 17:57:00 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	i = 0;
	if (s != NULL && f != NULL)
	{
		if ((s1 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) != NULL)
		{
			while (s[i])
			{
				s1[i] = (*f)(i, s[i]);
				i++;
			}
			s1[i] = '\0';
			return (s1);
		}
		return (NULL);
	}
	return (NULL);
}
