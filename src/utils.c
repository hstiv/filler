/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <satmak335@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:48:52 by hstiv             #+#    #+#             */
/*   Updated: 2020/12/03 18:48:54 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 				set_data(t_data *data)
{
	data->player = 79;
	data->map = NULL;
	data->fig = NULL;
	data->line = NULL;
	data->fsize[0] = 0;
	data->fsize[1] = 0;
	data->msize[0] = 0;
	data->msize[1] = 0;
	data->coor[0] = -1;
	data->coor[1] = -1;
	data->coor[2] = -1;
	data->hmap = NULL;
	data->enemy = 'x';
}

int 				ft_strlen2(char **s)
{
	int 			i;

	i = 0;
	while (s != NULL && s[i] != NULL)
		i++;
	return (i);
}

void 				reload_data(t_data *data)
{
	ft_arraydel((void **)data->fig);
	free(data->fig);
	data->fig = NULL;
	data->coor[0] = -1;
	data->coor[1] = -1;
	data->coor[2] = -1;
	data->fsize[0] = 0;
	data->fsize[1] = 0;
	data->line = NULL;
}

void 				throw(char *s)
{
	write(1, "hstiv.filler: ", 14);
	perror(s);
	exit(EXIT_FAILURE);
}

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
