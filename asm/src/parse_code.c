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

void	make_lab_token(char *name, t_asm *head, char *str)
{
	t_token	*tmp_token;
	int	i;

	i = -1;
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
	int	i;
	t_label	*tmp_label;

	i = -1;
	if (head->label == NULL)
	{
		head->label = ft_memalloc(sizeof(t_label));
		while (line[++i] == ' ' || line[i] == '\t')
			;
		head->label->name = ft_strndup(line + i, ft_strchr(line, LABEL_CHAR) - line);
		head->label->pos = head->b_pos;
		make_lab_token(head->label->name, head, line);
		return ;
	}
	tmp_label = head->label;
	while (tmp_label->next)
		tmp_label = tmp_label->next;
	tmp_label->next = ft_memalloc(sizeof(t_label));
	while (line[++i] == ' ' || line[i] == '\t')
			;
	tmp_label->next->name = ft_strndup(line + i, ft_strchr(line, LABEL_CHAR) - line);
	tmp_label->next->pos = head->b_pos;
	make_lab_token(tmp_label->next->name, head, line);
}

void	parse_code(t_asm *head, char *line)
{
	// t_label	*tmp;
	// t_token	*tmp2;

	if (is_label(line))
		make_label(head, line);
	else if (!empty_line(line))
		make_tokens(head, line);
	free(line);
	while (get_next_line(head->fd_s, &line))
	{
		if (is_label(line))
			make_label(head, line);
		else if (!empty_line(line))
			make_tokens(head, line);
		free(line);
	}
// 	tmp = head->label;
// 	printf("-----------labels------------\n");
// 	while (tmp)
// 	{
// 		printf("%s %d\n", tmp->name, tmp->pos);
// 		tmp = tmp->next;
// 	}
// 	printf("-----------tokens------------\n");
// 	tmp2 = head->token;
// 	while (tmp2)
// 	{
// 		printf("%s %d [%d]\n", tmp2->name, tmp2->type, tmp2->pos);
// 		tmp2 = tmp2->next;
// 	}
}