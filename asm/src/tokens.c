#include "op.h"
#include "asm.h"

// if (ft_strchr((*mass)[i], LABEL_CHAR))
// 			(*cur)->type = DIR_L;
// 		else
// 		{
// 			ft_check_digit((*cur)->value + 1);
// 			(*cur)->type = DIR;
// 		}
// 	}
// 	else
// 	{
// 		ft_check_ind((*mass)[i], labels);
// 		if (ft_strchr((*mass)[i], LABEL_CHAR))
// 			(*cur)->type = IND_L;
// 		else
// 			(*cur)->type = IND;
// 		g_code_size += 2;
// 	}

int		what_arg(char *str)
{
	if (str[0] == 'r')
		return (1);
	if (str[0] == DIRECT && ft_strchr(str, LSBEL_CHAR))
		return (5);
	if (str[0] == DIRECT_CHAR)
	{
		//проверить чтобы было число после %
		return (2);
	}

	return (2);
}

void	new_token(char	*str, t_asm *head)
{
	t_token	*tmp_token;


	if (head->token == NULL)
	{
		head->token = ft_memalloc(sizeof(t_token));
		head->token->name = ft_strdup(str);
		head->token->type = what_arg(str);
		return ;
	}
	tmp_token = head->token;
	while (tmp_token->next)
		tmp_token = tmp_token->next;
	tmp_token->next = ft_memalloc(sizeof(t_token));
	tmp_token->next->name = ft_strdup(str);
	tmp_token->next->type = what_arg(str);
}

void	op_token(t_asm *head, char **str)
{
	t_token	*tmp_token;

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

	i = 0;
	split = ft_strsplit(line, SEPARATOR_CHAR);
	del = split[i];
	split[i] = ft_strtrim(split[0]);
	free(del);
	op_token(head, &split[0]);
	while (split[i])
	{
		del = split[i];
		split[i] = ft_strtrim(split[i]);
		free(del);
		new_token(split[i], head);
		printf("%s\n", split[i]);
		i++;
	}
}
