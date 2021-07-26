#include "bsq.h"

void	ft_putstr_err(char *str)
{
	write(2, str, ft_strlen(str));
}
