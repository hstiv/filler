/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <satmak335@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:48:28 by hstiv             #+#    #+#             */
/*   Updated: 2020/12/03 18:48:30 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 				main(void)
{
	t_data			data;

	set_data(&data);
	if (!read_player(&data))
		exit(-1);
	while (read_board(&data))
	{
		init_heatmap(&data);
		handle_heatmap(&data);
		init_coordinates(&data);
		reload_data(&data);
	}
	return (0);
}
