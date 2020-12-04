#ifndef VIZU_H
# define VIZU_H

# include "libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>

# define HEIGHT		720
# define WIDTH		1000
# define WHITE		16777215
# define GREEN		65280
# define RED		16711680
# define YELLOW		65525
# define ORANGE		16682752
# define PINK		16715426
# define W4			WIDTH - 300
# define THRD		8
# define WIND		"fract'ol"

typedef struct	s_mlx
{
	void		*ptr;
	void		*wind;
	void		*img;
	int			*picture;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	char 		**map;
	char 		*players[2];
	int 		msize[2];
	int 		fsize[2];

}				t_mlx;

int				expose_hook(void *param);
int				draw_map(t_mlx *mlx);
void			read_map(t_mlx *mlx);

#endif