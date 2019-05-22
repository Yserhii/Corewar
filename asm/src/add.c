
#include "op.h"
#include "asm.h"

void	add(t_token *tmp_token, t_asm *head)
{
	int	n;
	int	i;

	i = 0;
	hex_con(4, 1, head);
	hex_con(84, 1, head);
	while (i < 3)
	{
		if (tmp_token->next->type != REG)
			error("Bat argument for operation add", tmp_token->next->name);
		n = ft_atoi(tmp_token->next->name + 1);
		hex_con(n, 1, head);
		tmp_token = tmp_token->next;
		i++;
	}
}
