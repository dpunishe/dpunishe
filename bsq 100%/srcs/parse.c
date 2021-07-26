#include "bsq.h"

int	get_params(t_params *par, char *map)
{
	int			i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	par->p = map[i - 3];
	map[i - 3] = '\0';
	par->o = map[i - 2];
	map[i - 2] = '\0';
	par->x = map[i - 1];
	map[i - 1] = '\0';
	if (par->p == par->o || par->p == par->x
		|| par->o == par->x)
		return (0);
	if (!is_numeric(map))
		return (0);
	par->lines = ft_atoi(map);
	if (par->lines < 1)
		return (0);
	return (i);
}

int	is_valid(t_params *par, char *map)
{
	int		len_par;
	int		length;
	int		i;

	len_par = get_params(par, map);
	if (len_par == '0')
		return (0);
	length = 0;
	i = 0;
	costil_2 (par, map, len_par);
	while (par->map[i])
	{
		if (par->map[i] != par->p && par->map[i] != par->o
			&& par->map[i] != '\n')
			return (0);
		if (par->map[i] == '\n')
		{
			if (par->map[i + 1]
				&& ft_strlen_nl(par->map + i + 1) != par->columns)
				return (0);
			length++;
		}
		i++;
	}
	return (length == par->lines);
}

void	fill_tab(t_params *par, int i, int j, int k)
{
	if (par->map[k] == par->p)
		par->tab[i][j] = 1
			+ ft_min(par->tab[i - 1][j], par->tab[i][j - 1],
				 par->tab[i - 1][j - 1]);
	else if (par->map[k] == par->o)
		par->tab[i][j] = 0;
	if (par->tab[i][j] > par->max)
	{
		par->max = par->tab[i][j];
		par->max_i = i;
		par->max_j = j;
	}
}

int	ft_bzero(t_params *par)
{
	int		i;
	int		j;

	i = 0;
	while (i < par->lines + 1)
	{
		par->tab[i] = (int *)malloc(sizeof(int) * (par->columns + 1));
		if (par->tab[i] == NULL)
			return (0);
		j = 0;
		while (j < par->columns + 1)
			par->tab[i][j++] = 0;
		i++;
	}
	return (1);
}

int	parse_map(t_params *par)
{
	int		i;
	int		j;
	int		k;

	par->tab = (int **)malloc(sizeof(int *) * (par->lines + 1));
	if (par->tab == NULL)
		return (0);
	if (!ft_bzero(par))
		return (0);
	k = 0;
	i = 1;
	while (i < par->lines + 1)
	{
		j = 1;
		while (j < par->columns + 1)
		{
			if (par->map[k] == '\n')
				k++;
			fill_tab(par, i, j++, k++);
		}
		i++;
	}
	return (1);
}
