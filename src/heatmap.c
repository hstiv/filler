/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <satmak335@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:48:11 by hstiv             #+#    #+#             */
/*   Updated: 2020/12/03 18:48:16 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			put_heap(t_data *data, int x, int y, int i)
{
	int 			**hmap;

	hmap = data->hmap;
	if (x + 1 < data->msize[0] && y + 1 < data->msize[1] && hmap[x + 1][y + 1] == i)
		hmap[x][y] = i + 1;
	else if (x + 1 < data->msize[0] && hmap[x + 1][y] == i)
		hmap[x][y] = i + 1;
	else if (x + 1 < data->msize[0] && y - 1 >= 0 && hmap[x + 1][y - 1] == i)
		hmap[x][y] = i + 1;
	else if (y - 1 >= 0 && hmap[x][y - 1] == i)
		hmap[x][y] = i + 1;
	else if (x - 1 >= 0 && y - 1 >= 0 && hmap[x - 1][y - 1] == i)
		hmap[x][y] = i + 1;
	else if (x - 1 >= 0 && hmap[x - 1][y] == i)
		hmap[x][y] = i + 1;
	else if (x - 1 >= 0 && y + 1 < data->msize[1] && hmap[x - 1][y + 1] == i)
		hmap[x][y] = i + 1;
	else if (y + 1 < data->msize[1] && hmap[x][y + 1] == i)
		hmap[x][y] = i + 1;
}

void 				handle_heatmap(t_data *data)
{
	int 			x;
	int 			y;
	int 			i;

	i = 1;
	while (i < (data->msize[0] >= data->msize[1] ? data->msize[0] : data->msize[1]))
	{
		x = 0;
		while (x < data->msize[0])
		{
			y = 0;
			while (y < data->msize[1])
			{
				if (data->hmap[x][y] == 0)
					put_heap(data, x, y, i);
				y++;
			}
			x++;
		}
		i++;
	}
}

static void			near_the_enemy(t_data *data, int x, int y)
{
	if (x + 1 < data->msize[0] && y + 1 < data->msize[1] && data->hmap[x + 1][y + 1] == 0)
		data->hmap[x + 1][y + 1] = 1;
	if (x + 1 < data->msize[0] && data->hmap[x + 1][y] == 0)
		data->hmap[x + 1][y] = 1;
	if (x + 1 < data->msize[0] && y - 1 >= 0 && data->hmap[x + 1][y - 1] == 0)
		data->hmap[x + 1][y - 1] = 1;
	if (y - 1 >= 0 && data->hmap[x][y - 1] == 0)
		data->hmap[x][y - 1] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && data->hmap[x - 1][y - 1] == 0)
		data->hmap[x - 1][y - 1] = 1;
	if (x - 1 >= 0 && data->hmap[x - 1][y] == 0)
		data->hmap[x - 1][y] = 1;
	if (x - 1 >= 0 && y + 1 < data->msize[1] && data->hmap[x - 1][y + 1] == 0)
		data->hmap[x - 1][y + 1] = 1;
	if (y + 1 < data->msize[1] && data->hmap[x][y + 1] == 0)
		data->hmap[x][y + 1] = 1;
}

void 				init_heatmap(t_data *data)
{
	int 			i;
	int 			j;
	char 			**map;

	i = 0;
	map = data->map;
	while (i < data->msize[0])
	{
		j = 0;
		while (j < data->msize[1])
		{
			if (map[i][j] == '.')
				data->hmap[i][j] = 0;
			else if (map[i][j] == data->player)
				data->hmap[i][j] = ME;
			else if (map[i][j] == data->enemy)
			{
				data->hmap[i][j] = EN;
				near_the_enemy(data, i, j);
			}
			j++;
		}
		i++;
	}
}

