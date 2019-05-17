
#include "op.h"
#include "asm.h"

void	live(t_token *tmp_token, t_asm *head)
{
	// char÷	*res;
	int		n;

	n = 0;
	if (tmp_token->next->type == DIR)
		n = ft_atoi(tmp_token->next->name +1);
	else if (tmp_token->next->type == DIR_L)
		n = head->b_pos - label_pos(head, tmp_token->next->name) + 1;//p_pos - lavel->pos + 1;
	else
		error ("Bat argument for operation live", tmp_token->next->name);
	head->hex_code = ft_strjoin(head->hex_code, hex_con(1, 1));
	head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 4));
}

// static void		ft_live_2(t_token **token, int *n)
// {
// 	char		*tmp;

// 	tmp = (*token)->value;
// 	(*token)->value = ft_strsub((*token)->value, 1,
// 	(int)(ft_strlen((*token)->value) - 1));
// 	ft_strdel(&tmp);
// 	(*n) = ft_atoi((*token)->value);
// }

// void			ft_live(t_token **token, t_label **labels, int fd2)
// {
// 	char	*res;
// 	int		n;

// 	n = 0;
// 	if ((*token)->next)
// 		(*token) = (*token)->next;
// 	g_byte_pos++;
// 	if ((*token)->type != 2 && (*token)->type != 5)
// 		ft_death("Bad argument for live!!!");
// 	if ((*token)->type == 2)
// 		ft_live_2(token, &n);
// 	else
// 	{
// 		n = ft_get_label_val((*token)->value + 1, labels);
// 		n = n - g_byte_pos + 1;
// 	}
// 	g_byte_pos += 4;
// 	res = ft_hex_conv(1, 1);
// 	ft_write(fd2, &res, 1);
// 	res = ft_hex_conv(n, 4);
// 	ft_write(fd2, &res, 4);
// }
