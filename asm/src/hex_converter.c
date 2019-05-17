
#include "op.h"
#include "asm.h"

char	*hex_con(int32_t num, int size)
{
	unsigned int	n;
	int				i;
	unsigned int	max;
	char			*str;

	if (size == 1)
		max = 255;
	if (size == 2)
		max = 65535;
	if (size == 4)
		max = 4294967295;
	if (num < 0)
		n = max + num + 1;
	else
		n = num;
	str = ft_strnew(size);
	i = size;
	while (--i >= 0)
	{
		str[i] = n % 256;
		n /= 256;
	}
	return (str);
}
