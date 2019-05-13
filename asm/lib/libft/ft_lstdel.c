/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:22:33 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/16 13:43:31 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*alst1;

	alst1 = (*alst);
	while (alst1 != NULL)
	{
		temp = alst1->next;
		del(alst1->content, alst1->content_size);
		free(alst1);
		alst1 = temp;
	}
	*alst = NULL;
}
