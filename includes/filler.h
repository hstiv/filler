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
# define FILLER_R

#include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 3

typedef struct	s_fil
{
    int			data;
	char		**map;
	char		**fig;
}				t_fil;

int					get_next_line(const int fd, char **line);

#endif