/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:13:44 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/10 13:13:46 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"


void	new_file(t_asm *head, char *file)
{
	char	*name;
	// char	*del;
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
	// del = name;
	name = ft_strjoin(name, "cor");
	// free(del);
	head->fd_cor = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0666);
}

void	error(char *str, char *line)
{
	if (line == NULL)
		ft_printf("%s", str);
	else
		ft_printf("%s [%s]\n", str, line);
	system("leaks asm > pip.txt");
	exit (0);
}

int		main(int argc, char **argv)
{
	t_asm	head;
	char	*res;

	if (argc != 2)
		error("Usage: ./asm <sourcefile.s>\n", NULL);
	check_file(argv[1]);
	head.fd_s = open(argv[1], O_RDONLY);
	new_file(&head, argv[1]);
	read_name_comment(&head);
	res = ft_strnew(4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + CHAMP_MAX_SIZE);
	write_magic(res, 0, COREWAR_EXEC_MAGIC, 4);
	ft_memcpy(res + 4, head.name, ft_strlen(head.name));
	ft_memcpy(res + 4 + 128 + 4 + 4, head.comment, ft_strlen(head.comment));
	printf("[%c]\n", *res);
	write(head.fd_cor, res, ft_strlen(res));
	system("leaks asm > pip.txt");
	return (0);
}
