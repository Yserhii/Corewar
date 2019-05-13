/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:06:25 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/02 15:03:37 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = f(lst);
	if (lst == NULL || f == NULL)
		return (NULL);
	if (lst->next != NULL && new != NULL)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
