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
	data->x = 0;
	data->y = 0;
	data->coor[0] = 0;
	data->coor[1] = 0;
	data->hmap = NULL;
	data->enemy = 'x';
}

int 				players_border(t_data *data, int x, int y)
{
	int 			**hmap;

	hmap = data->hmap;
	if (x + 1 < data->x && y + 1 < data->y && hmap[x + 1][y + 1] != ME)
		return (1);
	else if (x + 1 < data->x && hmap[x + 1][y] != ME)
		return (1);
	else if (x + 1 < data->x && y - 1 >= 0 && hmap[x + 1][y - 1] != ME)
		return (1);
	else if (y - 1 >= 0 && hmap[x][y - 1] != ME)
		return (1);
	else if (x - 1 >= 0 && y - 1 >= 0 && hmap[x - 1][y - 1] != ME)
		return (1);
	else if (x - 1 >= 0 && hmap[x - 1][y] != ME)
		return (1);
	else if (x - 1 >= 0 && y + 1 < data->y && hmap[x - 1][y + 1] != ME)
		return (1);
	else if (y + 1 < data->y && hmap[x][y + 1] != ME)
		return (1);
	return (0);
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
	data->coor[0] = 0;
	data->coor[0] = 0;
	data->line = NULL;
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
