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
	name = ft_strjoin(name, "cor");
	head->fd_cor = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(name);
}

void	error(char *str, char *line)
{
	if (line == NULL)
		ft_printf("%s", str);
	else
		ft_printf("%s [%s]\n", str, line);
	// system("leaks asm > pip.txt");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_asm	head;

	head.token = NULL;
	head.b_pos = 0;
	head.label = NULL;
	head.hex_code = ft_strdup("");
	if (argc != 2)
		error("Usage: ./asm <sourcefile.s>\n", NULL);
	check_file(argv[1]);
	head.fd_s = open(argv[1], O_RDONLY);
	new_file(&head, argv[1]);
	parse_code(&head, read_name_comment(&head));
	write_file(&head);
	code_to_hex(&head);
	system("leaks asm");
	return (0);
}
