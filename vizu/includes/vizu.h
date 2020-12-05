#ifndef VIZU_H
# define VIZU_H

# include "libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>

# define HEIGHT		1395
# define WIDTH		2560
# define WHITE		16777215
# define GREEN		65280
# define RED		16711680
# define YELLOW		65525
# define ORANGE		16682752
# define PINK		16715426
# define BLUE		4518094
# define W4			WIDTH - 300
# define CELL		5
# define WIND		"fract'ol"

typedef struct	s_mlx
{
	void		*ptr;
	void		*wind;
	void		*img;
	int			*picture;
	int 		pic_beg[2];
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	char 		**map;
	int 		msize[2];
	int 		result[2];
	int 		end;

}				t_mlx;

int				expose_hook(void *param);
void 			mlx_destroy(t_mlx *mlx);
int 			draw_map(t_mlx *mlx);
int 			ft_len2(char **s);
int 			players_init(t_mlx *mlx, char **s);
int 			map_init(t_mlx *mlx, char **s);
int 			end_anonce(t_mlx *mlx, char **s);
int 			create_map(t_mlx *mlx);
int 			read_map(t_mlx *mlx);
void 			create_img(t_mlx *mlx);
void 			put_map_on_picture(t_mlx *mlx);

#endif