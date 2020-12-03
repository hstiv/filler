/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:21:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/31 17:46:26 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "stdio.h"
# include <fcntl.h>

# define EN -2
# define ME -1

typedef struct	s_data
{
	char		**map;
	int			**hmap;
	char 		*line;
	char		**fig;
	char		player;
	char		enemy;
	int 		x;
	int 		y;
	int			coor[2];
}				t_data;

void 			set_data(t_data *data);
int				read_player(t_data *data);
int 			read_board(t_data *data);
char			*ft_strcpylower(char *dst, char const *src);
void 			init_heatmap(t_data *data);
void			init_coordinates(t_data *data);
void			handle_heatmap(t_data *data);
int 			players_border(t_data *data, int x, int y);
int 			ft_strlen2(char **s);
void 			reload_data(t_data *data);

#endif