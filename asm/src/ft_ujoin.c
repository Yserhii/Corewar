/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:28:41 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/29 16:28:49 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

char	*ft_ujoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	i;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	i = (ft_strlen(s1) + ft_strlen(s2));
	tmp = ft_strnew(i);
	ft_strcpy(tmp, s1);
	ft_strcpy(&tmp[ft_strlen(s1)], s2);
	free(s1);
	return (tmp);
}
