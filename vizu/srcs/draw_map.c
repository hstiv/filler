//
// Created by Hallie Stiv on 12/3/20.
//
#include "vizu.h"

int 				draw_map(t_mlx *mlx)
{
	char 			*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (players_init(mlx, line))
			read_player(mlx, line);
		else if (map_init(mlx, line))
			read_map(mlx, line);
		else if (fig_init(mlx, line))
			read_fig(mlx, line);
		else if (end_anonce(mlx, line))
			read_result(mlx, line);
		mlx_clear_window(mlx->ptr, mlx->wind);
		mlx_put_image_to_window(mlx->ptr, mlx->wind, mlx->img, 0, 0);
		ft_memdel(&line);
	}
}