/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:20:45 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 13:20:47 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	cod_operetion(char *op, t_asm *head)
{
	if (ft_strequ(op, "ld") || ft_strequ(op, "st") ||
		ft_strequ(op, "sub") || ft_strequ(op, "add") ||
		ft_strequ(op, "and") || ft_strequ(op, "or") ||
		ft_strequ(op, "sti") || ft_strequ(op, "xor") ||
		ft_strequ(op, "lld") || ft_strequ(op, "ldi") ||
		ft_strequ(op, "lldi"))
			head->b_pos++;
	else if (!ft_strequ(op, "live") && !ft_strequ(op, "zjmp") &&
			!ft_strequ(op, "fork") && !ft_strequ(op, "lfork"))
		error("Unfamiliar function", op);
}

char	*name_operation(char **str)
{
	int		i;
	char	*res;
	char	*tmp;

	i = 0;
	tmp = *str;
	while (tmp[i] && tmp[i] != ' ' && tmp[i] != '	')
		i++;
	res = ft_strndup(*str, i);
	*str = ft_strdup(*str + ft_strlen(res));
	return (res);
}

void	del_comment(char **line)
{
	char	*del;

	if (!ft_strchr(*line, '#'))
		return ;
	del = *line;
	*line = ft_strndup(*line, ft_strchr(*line, '#') - *line);
	free(del);
}
