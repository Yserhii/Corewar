/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:15:15 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:15:17 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	sub(t_token *tmp_token, t_asm *head)
{
	int	n;
	int	i;

	i = 0;
	hex_con(5, 1, head);
	hex_con(84, 1, head);
	tmp_token = tmp_token->next;
	while (i < 3)
	{
		if (!tmp_token || tmp_token->type == OP || tmp_token->type == LABEL)
			error("Too few arguments for sub\n", NULL);
		if (tmp_token->type != REG)
			error("Bad argument for operation sub", tmp_token->name);
		n = ft_atoi(tmp_token->name + 1);
		hex_con(n, 1, head);
		tmp_token = tmp_token->next;
		i++;
	}
	if (tmp_token && tmp_token->type != OP && tmp_token->type != LABEL)
		error("Too many arguments for sub\n", NULL);
}
