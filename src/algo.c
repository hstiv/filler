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

static void 	reload_coor(t_data *data, int x, int y)
{
	int 		fig_h;
	int 		fig_w;
	int 		curr[3];

	curr[0] = x;
	curr[1] = y;
	curr[2] = 0;
	fig_h = ft_strlen2(data->fig) + x;
	fig_w = ft_strlen(data->fig[0]) + y;
	while (x < fig_h)
	{
		y = fig_w - ft_strlen(data->fig[0]);
		while (y < fig_w)
		{
			curr[2] += data->hmap[x][y];
			y++;
		}
		x++;
	}
	if (curr[2] <= data->coor[2])
	{
		data->coor[0] = curr[0];
		data->coor[1] = curr[1];
		data->coor[2] = curr[2];
	}
}

static int 		check_fig_place(t_data *data, int x, int y)
{
	int 		fig_h;
	int 		fig_w;
	int 		block_count;

	fig_h = ft_strlen2(data->fig) + x;
	block_count = 0;
	fig_w = ft_strlen(data->fig[0]) + y;
	if (fig_h > data->x || fig_w > data->y)
		return (0);
	while (x < fig_h)
	{
		y = fig_w - ft_strlen(data->fig[0]);
		while (y < fig_w)
		{
			if (data->hmap[x][y] == ME)
				block_count++;
			if (data->hmap[x][y] == EN || block_count > 1)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void 			init_coordinates(t_data *data)
{
	int 		x;
	int 		y;

	x = 0;
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (check_fig_place(data, x, y))
				reload_coor(data, x, y);
			y++;
		}
		x++;
	}
	ft_putnbr(data->coor[0]);
	ft_putchar(' ');
	ft_putnbr(data->coor[1]);
	ft_putchar('\n');
}
