/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:07:11 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/15 13:07:13 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

char	*save_name(char *line, t_asm *head, int i, int j)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (ft_strncmp(line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		error("Syntax error", line);
	i += ft_strlen(NAME_CMD_STRING);
	while (line[i] && line[i] != '"')
	{
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
		i++;
	}
	while (line[++i] != '"')
	{
		if (line[i] == '\0')
		{
			free(line);
			get_next_line(head->fd_s, &line);
			head->name[j++] = '\n';
			i = 0;
		}
		head->name[j++] = line[i];
	}
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
	return (line);
}

char	*save_comment(char *line, t_asm *head, int i, int j)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (ft_strncmp(line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		error("Syntax error", line);
	i += ft_strlen(COMMENT_CMD_STRING);
	while (line[i] && line[i] != '"')
	{
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
		i++;
	}
	while (line[++i] != '"')
	{
		if (line[i] == '\0')
		{
			free(line);
			get_next_line(head->fd_s, &line);
			head->comment[j++] = '\n';
			i = 0;
		}
		head->comment[j++] = line[i];
	}
	i++;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
		i++;
	}
	return (line);
}

char	*read_name_comment(t_asm *head)
{
	char	*line;

	head->name = ft_strnew(PROG_NAME_LENGTH);
	head->comment = ft_strnew(COMMENT_LENGTH);
	while (get_next_line(head->fd_s, &line) && check_line(line))
	{
		if (ft_strstr(line, NAME_CMD_STRING))
			line = save_name(line, head, 0, 0);
		if (ft_strstr(line, COMMENT_CMD_STRING))
			line = save_comment(line, head, 0, 0);
		free(line);
	}
	if (ft_strlen(head->name) > PROG_NAME_LENGTH)
		error("Champion name too long (Max length 128)\n", NULL);
	if (ft_strlen(head->comment) > COMMENT_LENGTH)
		error("Comment too long (Max length 2048)\n", NULL);
	return (line);
}
