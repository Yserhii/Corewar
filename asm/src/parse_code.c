/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:14:52 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/24 12:14:55 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

int		label_pos(t_asm *head, char *label)
{
	t_label	*tmp_label;

	tmp_label = head->label;
	while (tmp_label)
	{
		if (ft_strequ(label + 1, tmp_label->name))
			return (tmp_label->pos);
		tmp_label = tmp_label->next;
	}
	error("Nonexistent label", label);
	return (0);
}

void	make_lab_token(char *name, t_asm *head, char *str, int i)
{
	t_token	*tmp_token;

	if (head->token == NULL)
	{
		head->token = ft_memalloc(sizeof(t_token));
		head->token->name = name;
		head->token->type = LABEL;
	}
	else
	{
		tmp_token = head->token;
		while (tmp_token->next)
			tmp_token = tmp_token->next;
		tmp_token->next = ft_memalloc(sizeof(t_token));
		tmp_token->next->name = name;
		tmp_token->next->type = LABEL;
	}
	while (str[++i] == ' ' || str[i] == '\t')
		;
	while (str[i++] != LABEL_CHAR)
		;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i])
		make_tokens(head, str + i);
}

void	make_label(t_asm *head, char *line)
{
	int		i;
	t_label	*tmp_label;

	i = -1;
	if (head->label == NULL)
	{
		head->label = ft_memalloc(sizeof(t_label));
		while (line[++i] == ' ' || line[i] == '\t')
			;
		head->label->name = ft_strndup(line + i,
		ft_strchr(line, LABEL_CHAR) - line);
		head->label->pos = head->b_pos;
		make_lab_token(head->label->name, head, line, -1);
		return ;
	}
	tmp_label = head->label;
	while (tmp_label->next)
		tmp_label = tmp_label->next;
	tmp_label->next = ft_memalloc(sizeof(t_label));
	while (line[++i] == ' ' || line[i] == '\t')
		;
	tmp_label->next->name = ft_strndup(line + i,
	ft_strchr(line, LABEL_CHAR) - line);
	tmp_label->next->pos = head->b_pos;
	make_lab_token(tmp_label->next->name, head, line, -1);
}

void	parse_code(t_asm *head, char *line)
{
	del_comment(&line);
	check_code_line(line);
	if (is_label(line))
		make_label(head, line);
	else if (!empty_line(line))
		make_tokens(head, line);
	free(line);
	while (get_next_line(head->fd_s, &line))
	{
		del_comment(&line);
		check_code_line(line);
		if (is_label(line))
			make_label(head, line);
		else if (!empty_line(line))
			make_tokens(head, line);
		free(line);
	}
	free(line);
}
