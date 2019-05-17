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

enum				e_type
{
	OP,  //0
	REG, //1
	DIR, //2
	IND, //3
	LABEL, //4
	DIR_L, //5
	IND_L //6
};

typedef struct		s_label
{
	char			*name;
	int				pos;
	struct s_label	*next;
}					t_label;

typedef struct		s_token
{
	enum e_type		type;
	char			*name;
	struct s_token	*next;
}					t_token;

typedef struct		s_asm
{
	t_token			*token;
	t_label			*label;
	int				fd_s;
	int				fd_cor;
	char			*name;
	char			*comment;
	int				b_pos;
}					t_asm;

void	check_file(char *file);
void	error(char *str, char *line);
void	new_file(t_asm *head, char *file);
char	*read_name_comment(t_asm *head);
void	write_magic(char *data, int32_t pos, int32_t value, size_t size);
void	write_file(t_asm *parser);
int		check_line(char	*line);
void	parse_code(t_asm *head, char *line);
int		is_label(char *line);
int		empty_line(char *line);
void	make_tokens(t_asm *head, char *line);
int		check_dir_reg(char *str);

#endif
