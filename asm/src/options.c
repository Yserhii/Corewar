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
		ft_strequ(op, "lldi") || ft_strequ(op, "aff"))
			head->b_pos++;
	else if (!ft_strequ(op, "live") && !ft_strequ(op, "zjmp") &&
			!ft_strequ(op, "fork") && !ft_strequ(op, "lfork"))
		error("Invalid instruction", op);
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
	if (empty_line(tmp + i))
		error("Syntax error\n", NULL);
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

void	check_code_line(char *line)
{
	if (ft_strchr(line, SEPARATOR_CHAR))
	{
		if (empty_line(ft_strrchr(line, SEPARATOR_CHAR)))
			error("Syntax error\n", NULL);
	}
}

int		check_ind(char *line)
{
	if (!*line)
		error("Syntax error\n", NULL);
	if (ft_allnum(line))
		error("Bad argument", line);
	return (1);
}
