#include "op.h"
#include "asm.h"

void	cod_operetion(char *op, t_asm *head)
{
	if (ft_strnequ(op, "ld", 2) || ft_strnequ(op, "st", 2) ||
		ft_strnequ(op, "sub", 3) || ft_strnequ(op, "add", 3) ||
		ft_strnequ(op, "and", 3) || ft_strnequ(op, "or", 2) ||
		ft_strnequ(op, "sti", 3) || ft_strnequ(op, "xor", 3) ||
		ft_strnequ(op, "lld", 3) || ft_strnequ(op, "ldi", 3) ||
		ft_strnequ(op, "lldi", 4))
			head->b_pos++;
	else if (!ft_strnequ(op, "live", 4) && !ft_strnequ(op, "zjmp", 4) &&
			!ft_strnequ(op, "fork", 4) && !ft_strnequ(op, "lfork", 5))
		error("unfamiliar function\n", NULL);
}

void	position(t_asm *head, char *op)
{
	t_token	*tmp_token;

	tmp_token = head->token;
	while (tmp_token->next)
		tmp_token = tmp_token->next;
	if (tmp_token->type == DIR || tmp_token->type == DIR_L)
	{
		if (ft_strnequ(op, "zjmp", 4) || ft_strnequ (op, "ldi", 3) ||
			ft_strnequ(op, "fork", 4) || ft_strnequ(op, "lfork", 5) ||
			ft_strnequ(op, "sti", 3) || ft_strnequ(op, "lldi", 4))
			head->b_pos += 2;
		else
			head->b_pos += 4;
	}
}

int		what_arg(char *str, t_asm *head)
{
	if (str[0] == 'r' && check_dir_reg(str))
	{
		head->b_pos++;
		return (1);
	}
	if (str[0] == DIRECT_CHAR && ft_strchr(str, LABEL_CHAR))
	{
		//check_dir_l;
		return (5);
	}
	if (str[0] == DIRECT_CHAR)
	{
		check_dir_reg(str);
		return (2);
	}
	if (ft_strchr(str, LABEL_CHAR)) //check int_l
		return (6);
	else
		//check_ind(str);
	return (3);
}

void	new_token(char	*str, t_asm *head, char *op)
{
	t_token	*tmp_token;


	if (head->token == NULL)
	{
		head->token = ft_memalloc(sizeof(t_token));
		head->token->name = ft_strdup(str);
		head->token->type = what_arg(str, head);
		position(head, op);
		return ;
	}
	tmp_token = head->token;
	while (tmp_token->next)
		tmp_token = tmp_token->next;
	tmp_token->next = ft_memalloc(sizeof(t_token));
	tmp_token->next->name = ft_strdup(str);
	tmp_token->next->type = what_arg(str, head);
	position(head, op);
}

void	op_token(t_asm *head, char **str)
{
	t_token	*tmp_token;

	head->b_pos++;
	cod_operetion(*str, head);
	if (head->token == NULL)
	{
		head->token = ft_memalloc(sizeof(t_token));
		head->token->name = ft_strndup(*str, ft_strchr(*str, ' ') - *str);
		head->token->type = OP;
		*str = ft_strdup(*str + ft_strlen(head->token->name));
		return ;
	}
	tmp_token = head->token;
	while (tmp_token->next)
		tmp_token = tmp_token->next;
	tmp_token->next = ft_memalloc(sizeof(t_token));
	tmp_token->next->name = ft_strndup(*str, ft_strchr(*str, ' ') - *str);
	tmp_token->next->type = OP;
	*str = ft_strdup(*str + ft_strlen(tmp_token->next->name));
}

void	make_tokens(t_asm *head, char *line)
{
	char	**split;
	int		i;
	char	*del;
	char	*op;

	i = 0;
	split = ft_strsplit(line, SEPARATOR_CHAR);
	del = split[0];
	split[0] = ft_strtrim(split[0]);
	free(del);
	op = split[0];
	op_token(head, &split[0]);
	while (split[i])
	{
		del = split[i];
		split[i] = ft_strtrim(split[i]);
		free(del);
		new_token(split[i], head, op);
		i++;
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
