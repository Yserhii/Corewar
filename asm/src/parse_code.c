#include "op.h"
#include "asm.h"

// void	parse_line(t_asm *head, char *line)
// {
// 	if (is_label(line))
// 		printf("1n");
// 	else
// 		printf("0\n");
// 	head->token = NULL;
// }



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
}

void	parse_code(t_asm *head, char *line)
{
	t_label	*tmp;
	t_token	*tmp2;

	if (is_label(line))
		make_label(head, line);
	else if (!empty_line(line))
		printf("not label\n");
	// parse_line(head, line);
	free(line);
	while (get_next_line(head->fd_s, &line))
	{
		if (is_label(line))
			make_label(head, line);
		else if (!empty_line(line))
			make_tokens(head, line);
			// nes_token(head, line);
		// parse_line(head, line);
		free(line);
	}
	tmp = head->label;
	printf("-----------labels------------\n");
	while (tmp)
	{
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	printf("-----------tokens------------\n");
	tmp2 = head->token;
	while (tmp2)
	{
		printf("%s %d\n", tmp2->name, tmp2->type);
		tmp2 = tmp2->next;
	}
}
