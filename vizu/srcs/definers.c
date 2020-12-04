//
// Created by Hallie Stiv on 12/4/20.
//
#include "vizu.h"

int 				ft_len2(char **s)
{
	int 			i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int 				players_init(t_mlx *mlx, char *line)
{
	if (line == NULL)
		return (0);
	s = ft_strsplit(line, ' ');
	if (ft_len2(s) == 5)
	{
		if (ft_strcmp(s[2], "p1") == 0)
			mlx->players[0] = ft_strdup(s[2]);
		else
			mlx->players[1] = ft_strdup(s[2]);
		return (1);
	}
	return (0);
}

int 				map_init(t_mlx *mlx, char *line)
{

}

int 				fig_init(t_mlx *mlx, char *line)
{

}

int 				end_anonce(t_mlx *mlx, char *line)
{

}
