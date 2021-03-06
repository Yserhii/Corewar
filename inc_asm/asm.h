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
# define ALT_COMMENT_CHAR	';'

enum				e_type
{
	OP,
	REG,
	DIR,
	IND,
	LABEL,
	DIR_L,
	IND_L
};

typedef struct		s_file
{
	char			*line;
	struct s_file	*next;
}					t_file;

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
	int				pos;
	struct s_token	*next;
}					t_token;

typedef struct		s_asm
{
	t_file			*f;
	t_token			*token;
	t_label			*label;
	int				fd_s;
	int				fd_cor;
	char			*name;
	char			*comment;
	int				b_pos;
}					t_asm;

void				check_file(char *file);
void				error(char *str, char *line);
void				new_file(t_asm *head, char *file);
char				*read_name_comment(t_asm *head);
void				write_magic(char *data, int32_t pos, int32_t
					value, size_t size);
void				write_file(t_asm *parser);
int					check_line(char	*line);
void				parse_code(t_asm *head, char *line);
int					is_label(char *line);
int					empty_line(char *line);
void				make_tokens(t_asm *head, char *line);
int					check_dir_reg(char *str, int fl);
void				hex_con(int32_t num, int size, t_asm *head);
void				code_to_hex(t_asm *head);
void				cod_operetion(char *op, t_asm *head);
char				*name_operation(char **str);
void				del_comment(char **line);

void				live(t_token *tmp_token, t_asm *head);
void				st(t_token *tmp_token, t_asm *head);
void				ld(t_token *tmp_token, t_asm *head, int nb);
void				add(t_token *tmp_token, t_asm *head);
void				sub(t_token *tmp_token, t_asm *head);
void				ft_and_or(t_token *tmp_token, t_asm *head, int nb);
void				zjmp(t_token *tmp_token, t_asm *head);
void				ldi(t_token *tmp_token, t_asm *head, int nb);
void				sti(t_token *tmp_token, t_asm *head);
void				ft_fork(t_token *tmp_token, t_asm *head, int nb);
void				aff(t_token *tmp_token, t_asm *head);

int					label_pos(t_asm *head, char *label);
void				check_code_line(char *line);
int					check_ind(char *line);
char				*what_op(char *str);

void				valid_code(t_asm *head);
void				valid_add(t_token *token);
void				valid_aff(t_token *token);
void				valid_fork(t_token *token, int nb, t_asm *head);
void				valid_and_or(t_token *token, int nb, t_asm *head);
void				valid_ld(t_token *token, int nb, t_asm *head);
void				valid_ldi(t_token *token, int nb, t_asm *head);
void				valid_live(t_token *token, t_asm *head);
void				valid_st(t_token *token, t_asm *head);
void				valid_sti(t_token *token, t_asm *head);
void				valid_sub(t_token *token);
void				valid_zjmp(t_token *token, t_asm *head);

#endif
