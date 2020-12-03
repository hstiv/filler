/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <satmak335@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:47:57 by hstiv             #+#    #+#             */
/*   Updated: 2020/12/03 18:48:01 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void 	min_border(t_data *data)
{
	int 		x;
	int 		y;

	x = 0;
	data->coor[0] = 0;
	data->coor[1] = 0;
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (data->hmap[x][y] == ME && players_border(data, x, y) && data->hmap[x][y] != -3)
			{
				data->coor[0] = x;
				data->coor[1] = y;
			}
			y++;
		}
		x++;
	}
}

static int 		try_to_put_figure(t_data *data, int fig_x, int fig_y)
{
	int 		fig_h;
	int 		fig_w;
	int 		x;
	int 		y;

	fig_h = ft_strlen2(data->fig);
	fig_w = ft_strlen(data->fig[0]);
	x = data->coor[0] - fig_x;
	while (x < fig_h)
	{
		y = data->coor[1] - fig_y;
		while (y < fig_w)
		{
			if (data->hmap[x][y] == EN ||
				(data->hmap[x][y] == ME && x != data->coor[0] && y != data->coor[1]))
			{
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

static int 		is_acceptable_coordinate(t_data *data)
{
	int 		fig_x;
	int 		fig_y;
	int 		x;
	int 		y;

	fig_x = ft_strlen2(data->fig);
	fig_y = ft_strlen(data->fig[0]);
	x = 0;
	while (x < fig_x)
	{
		y = 0;
		while (y < fig_y)
		{
			if (data->fig[x][y] == '*' &&
				((x + 1 == fig_x || x - 1 < 0) ||
				(y + 1 == fig_y || y - 1 < 0)) &&
				try_to_put_figure(data, x, y)
			) {
				return (1);
			}
			y++;
		}
		x++;
	}
	data->hmap[data->coor[0]][data->coor[1]] = -3;
	return (0);
}

void 			init_coordinates(t_data *data)
{
	min_border(data);
	while (!(is_acceptable_coordinate(data)))
		min_border(data);
	ft_putnbr(data->coor[0]);
	ft_putchar(' ');
	ft_putnbr(data->coor[1]);
	ft_putchar('\n');
}
