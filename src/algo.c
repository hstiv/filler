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
	fig_h = 0;
	while (fig_h < data->fsize[0])
	{
		fig_w = 0;
		while (fig_w < data->fsize[1])
		{
			if (data->fig[fig_h][fig_w] == '*')
				curr[2] += data->hmap[x + fig_h][y + fig_w];
			fig_w++;
		}
		fig_h++;
	}
	if (curr[2] <= data->coor[2] || data->coor[2] == 0)
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

	block_count = 0;
	fig_h = 0;
	if (x + data->fsize[0] > data->msize[0] ||
		y + data->fsize[1] > data->msize[1])
		return (0);
	while (fig_h < data->fsize[0])
	{
		fig_w = 0;
		while (fig_w < data->fsize[1])
		{
			if (data->hmap[x + fig_h][y + fig_w] == ME && data->fig[fig_h][fig_w] == '*')
				block_count++;
			if ((data->hmap[x + fig_h][y + fig_w] == EN && data->fig[fig_h][fig_w] == '*') || block_count > 1)
				return (0);
			fig_w++;
		}
		fig_h++;
	}
	return (block_count);
}

void 			init_coordinates(t_data *data)
{
	int 		x;
	int 		y;

	x = 0;
	while (x < (data->msize[0]))
	{
		y = 0;
		while (y < data->msize[1])
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
