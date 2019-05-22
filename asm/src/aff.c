
#include "op.h"
#include "asm.h"

void	aff(t_token *tmp_token, t_asm *head)
{
	int	n;

	head->hex_code = ft_strjoin(head->hex_code, hex_con(16, 1));
	head->hex_code = ft_strjoin(head->hex_code, hex_con(64, 1));
	if (tmp_token->next->type != REG)
		error("Bat argument for operation aff", tmp_token->next->name);
	n = ft_atoi(tmp_token->next->name + 1);
	head->hex_code = ft_strjoin(head->hex_code, hex_con(n, 1));
}
