#include "bsq.h"

int	ft_strlen_nl(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}
