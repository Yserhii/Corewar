/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:12:15 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:12:18 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	valid_add(t_token *token)
{
	int	i;

	i = 0;
	token = token->next;
	while (i < 3)
	{
		if (!token || token->type == OP || token->type == LABEL)
			error("Too few arguments for add\n", NULL);
		if (token->type != REG)
			error("Bad argument for operation add", token->name);
		i++;
		token = token->next;
	}
	if (token && token->type != OP && token->type != LABEL)
		error("Too many arguments for add\n", NULL);
}

void	add(t_token *tmp_token, t_asm *head)
{
	int	n;
	int	i;

	i = 0;
	hex_con(4, 1, head);
	hex_con(84, 1, head);
	tmp_token = tmp_token->next;
	while (i < 3)
	{
		n = ft_atoi(tmp_token->name + 1);
		hex_con(n, 1, head);
		tmp_token = tmp_token->next;
		i++;
	}
}
