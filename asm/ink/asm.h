/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:19:36 by yhliboch          #+#    #+#             */
/*   Updated: 2019/05/10 13:19:38 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"

typedef struct		s_asm
{
	int				fd_s;
	int				fd_cor;
	char			*name;
	char			*comment;
}					t_asm;

void	check_file(char *file);
void	error(char *str, char *line);
void	new_file(t_asm *head, char *file);
char	*read_name_comment(t_asm *head);
void	write_magic(char *data, int32_t pos, int32_t value, size_t size);
void	write_file(t_asm *parser);
int		check_line(char	*line);



// void	write_magic(int32_t pos, int32_t value,size_t size, t_asm *head);

#endif
