/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:38:40 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/16 16:22:50 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *src, size_t content_size)
{
	t_list	*newlst;

	if ((newlst = (t_list *)malloc(sizeof(t_list) * 1)) != NULL)
	{
		if (src == NULL)
		{
			newlst->content = NULL;
			newlst->content_size = 0;
		}
		else
		{
			newlst->content = ft_strdup(src);
			newlst->content_size = content_size;
		}
		newlst->next = NULL;
		return (newlst);
	}
	return (NULL);
}
