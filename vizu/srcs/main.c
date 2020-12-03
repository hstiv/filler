include "vizu.h"

int				expose_hook(void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->ptr, mlx->wind);
	exit(0);
}

static void			loop(t_mlx *mlx)
{
	mlx_hook(mlx->wind, 17, (1L << 17), expose_hook, mlx);
	mlx_loop_hook(mlx->ptr, draw_map, mlx);
	mlx_loop(mlx->ptr);
}

int 				main(void)
{
	t_mlx			mlx;

	mlx.ptr = mlx_init();
	mlx.img = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx.wind = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, WIND);
	mlx.picture = (int *)mlx_get_data_addr(mlx.img,
	&mlx.bit_per_pixel, &mlx.size_line, &mlx.endian);
	loop(&mlx);
	exit(0);
}