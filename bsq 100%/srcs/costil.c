#include "bsq.h"
int	costil_1(t_params	*par)
{
	par->max = 0;
	par->max_i = 0;
	par->max_j = 0;
	if (!parse_map(par))
		return (1);
	display_bsq(par);
	return (0);
}

void	costil_2(t_params *par, char *map, int	len_par)
{
	par->map = map + len_par + 1;
	par->columns = ft_strlen_nl(par->map);
}
