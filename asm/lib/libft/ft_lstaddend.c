/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:51:38 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/26 15:51:39 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = (*alst);
	if (*alst == NULL || new == NULL)
		return ;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
