//
// Created by Hallie Stiv on 12/3/20.
//
#include "vizu.h"

void 			put_cell(t_mlx *mlx, int cell, int pic_cor)
{
	int 		x;
	int 		y;

	x = 0;
	while (x < CELL)
	{
		y = 0;
		while (y < CELL)
		{
			mlx->picture[pic_cor + (x * WIDTH) + y] = cell;
			y++;
		}
		x++;
	}
}

void 			put_map_on_picture(t_mlx *mlx)
{
	int 		x;
	int 		y;
	int 		cell;
	int 		pic_cor;
	int 		beg;

	mlx->pic_beg[0] = (HEIGHT - (mlx->msize[0] * CELL + mlx->msize[0] + 1)) / 2;
	mlx->pic_beg[1] = (WIDTH - (mlx->msize[1] * CELL + mlx->msize[1] + 1)) / 2;
	x = 0;
	beg = mlx->pic_beg[0] * WIDTH + mlx->pic_beg[1];
	while (x < mlx->msize[0])
	{
		y = 0;
		while (y < mlx->msize[1])
		{
			if (mlx->map[x][y] == '.')
				cell = WHITE;
			else if (mlx->map[x][y] == 'x')
				cell = YELLOW;
			else if (mlx->map[x][y] == 'o')
				cell = BLUE;
			pic_cor = beg + (x * WIDTH * CELL + x + 1) + (y * CELL + y + 1);
			put_cell(mlx, cell, pic_cor);
			y++;
		}
		x++;
	}
}

void 			mlx_destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->wind);
	exit(0);
}

int 			draw_map(t_mlx *mlx)
{
	char 		*line;
	char 		**s;

	line = NULL;
	s = NULL;
	while (mlx->end != 0 && get_next_line(0, &line) >= 0)
	{
		s = ft_strsplit(line, ' ');
		ft_memdel((void **)&line);
		if (map_init(mlx, s))
			put_map_on_picture(mlx);
//		else if (end_anonce(mlx, s))
//			create_img(mlx);
		mlx_clear_window(mlx->ptr, mlx->wind);
		mlx_put_image_to_window(mlx->ptr, mlx->wind, mlx->img, 0, 0);
		ft_arraydel((void **)s);
		free(s);
	}
	mlx_destroy(mlx);
	return (1);
}