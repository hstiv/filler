//
// Created by Hallie Stiv on 12/4/20.
//
#include "vizu.h"

int 			ft_len2(char **s)
{
	int 		i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int 			map_init(t_mlx *mlx, char **s)
{
	if (ft_len2(s) == 3 && strcmp(s[0], "Plateau") == 0)
	{
		if (mlx->map == NULL)
		{
			mlx->msize[0] = atoi(s[1]);
			mlx->msize[1] = atoi(s[2]);
			create_map(mlx);
		}
		read_map(mlx);
		return (1);
	}
	return (0);
}

int 			end_anonce(t_mlx *mlx, char **s)
{
	char 		*line;

	line = NULL;
	if (ft_len2(s) == 4 && strcmp(s[2], "fin:") == 0)
	{
		if (strcmp(s[1], "O") == 0)
		{
			mlx->result[0] = atoi(s[3]);
			get_next_line(0, &line);
			end_anonce(mlx, ft_strsplit(line, ' '));
			ft_memdel((void **)&line);
		}
		else
		{
			mlx->result[1] = atoi(s[3]);
			ft_arraydel((void **)s);
			free(s);
		}
		mlx->end = 1;
		return (1);
	}
	return (0);
}
