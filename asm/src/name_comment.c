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

char	*rem_name(char *line, int *i, t_asm *head)
{
	int	r;
	int	j;

	j = 0;
	r = 1;
	while (line[++(*i)] != '"' && r > 0)
	{
		if (line[*i] == '\0')
		{
			free(line);
			r = get_next_line(head->fd_s, &line);
			head->name[j++] = '\n';
			*i = 0;
		}
		if (j >= PROG_NAME_LENGTH)
			error("Champion name too long (Max length 128)\n", NULL);
		head->name[j++] = line[*i];
	}
	if (r <= 0)
		error("Syntax error in name\n", NULL);
	return (line);
}

char	*save_name(char *line, t_asm *head, int i)
{
	int r;

	r = 1;
	if (head->name != NULL)
		error("More then one champion name\n", NULL);
	head->name = ft_strnew(PROG_NAME_LENGTH);
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
	if (!line[i])
		error("Syntax error", line);
	line = rem_name(line, &i, head);
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
	return (line);
}

char	*rem_comment(char *line, int *i, t_asm *head)
{
	int	r;
	int	j;

	j = 0;
	r = 1;
	while (line[++(*i)] != '"' && r > 0)
	{
		if (line[*i] == '\0')
		{
			free(line);
			r = get_next_line(head->fd_s, &line);
			head->comment[j++] = '\n';
			(*i) = 0;
		}
		if (j >= COMMENT_LENGTH)
			error("Comment too long (Max length 2048)\n", NULL);
		head->comment[j++] = line[*i];
	}
	if (r <= 0)
		error("Syntax error in comment\n", NULL);
	return (line);
}

char	*save_comment(char *line, t_asm *head, int i)
{
	int	r;

	r = 1;
	if (head->comment != NULL)
		error("More then one comment\n", NULL);
	head->comment = ft_strnew(COMMENT_LENGTH);
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
	if (!line[i])
		error("Syntax error", line);
	line = rem_comment(line, &i, head);
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
			error("Syntax error", line);
	return (line);
}

char	*read_name_comment(t_asm *head)
{
	char	*line;

	while (get_next_line(head->fd_s, &line) && check_line(line))
	{
		if (ft_strstr(line, NAME_CMD_STRING))
			line = save_name(line, head, 0);
		else if (ft_strstr(line, COMMENT_CMD_STRING))
			line = save_comment(line, head, 0);
		free(line);
	}
	if (head->name == NULL)
		error("No champion name\n", NULL);
	if (head->comment == NULL)
		error("No comment\n", NULL);
	return (line);
}
