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
#include "stdio.h"
#include <fcntl.h>

typedef struct	s_data
{
	char		**map;
	char 		*line;
	char		**fig;
	char		player;
	char		enemy;
}				t_data;

void 				set_data(t_data *data);
int					read_player(t_data *data);
int 				read_board(t_data *data);
void 				put_figure(t_data *data);
char				*ft_strcpymap(char *dst, char const *src, char (*f)(char));

#endif