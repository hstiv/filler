//
// Created by Hallie Stiv on 12/3/20.
//
#include "vizu.h"

char				*ft_strcpylower(char *dst, char const *src)
{
	int				i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = (char)ft_tolower(src[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int 			create_map(t_mlx *mlx)
{
	int 		x;

	x = 0;
	mlx->map = (char **)malloc(sizeof(char *) * (mlx->msize[0] + 1));
	while (x < mlx->msize[0])
	{
		mlx->map[x] = ft_strnew(mlx->msize[1]);
		x++;
	}
	mlx->map[x] = NULL;
	return (1);
}

int 			read_map(t_mlx *mlx)
{
	char 		*line;
	char 		**s;
	char 		x;

	line = NULL;
	s = NULL;
	x = 0;
	get_next_line(0, &line);
	ft_memdel((void **)&line);
	while (x < mlx->msize[0])
	{
		get_next_line(0, &line);
		s = ft_strsplit(line, ' ');
		ft_memdel((void **)&line);
		if (x == atoi(s[0]))
			mlx->map[x] = ft_strcpylower(mlx->map[x], s[1]);
		else
			mlx_destroy(mlx);
		ft_arraydel((void **)s);
		free(s);
		x++;
	}
	return (1);
}

