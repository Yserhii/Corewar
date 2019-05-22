
#include "op.h"
#include "asm.h"

void	sub(t_token *tmp_token, t_asm *head)
{
	int	n;
	int	i;

	i = 0;
	head->hex_code = ft_strjoin(head->hex_code, hex_con(5, 1));
	head->hex_code = ft_strjoin(head->hex_code, hex_con(84, 1));
	while (i < 3)
	{
		if (tmp_token->next->type != REG)
			error("Bat argument for operation sub", tmp_token->next->name);
		n = ft_atoi(tmp_token->next->name + 1);
		head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
		tmp_token = tmp_token->next;
		i++;
	}
}
