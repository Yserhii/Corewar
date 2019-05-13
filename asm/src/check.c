/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:39:15 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/10 13:39:16 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

void	new_file(t_asm *head, char *file)
{
	char	*name;
	char	*del;
	int		i;
	int		j;

	j = ft_strrchr(file, '.') - file + 1;
	name = ft_strnew(j);
	i = 0;
	while (file[i] && i != j)
	{
		name[i] = file[i];
		i++;
	}
	del = name;
	name = ft_strjoin(name, "cor");
	free(del);
	head->fd_cor = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	// записать magic header
}

void	check_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 's' || file[i - 2] != '.')
		error("Usage: ./asm <sourcefile.s>\n");
}

int		empty_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return (1);
	while (line[++i])
		if (line[i] != '\n' && line[i] != ' ')
			return (0);
	return (1);
}

void	give_name(t_asm *head)
{
	char	*line;

	printf("%d\n", get_next_line(head->fd_cor, &line));
	free(line);
	get_next_line(head->fd_cor, &line);
	printf("[%s]\n", line);
	printf("%d\n", empty_line(line));
}
