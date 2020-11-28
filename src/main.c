//
// Created by Hallie Stiv on 11/26/20.
//
#include "filler.h"

static void 		print_fig_map(t_data *data)
{
	int 			i = 0;

	while (data->map[i] != NULL)
	{
		ft_putstr(data->map[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (data->fig[i] != NULL)
	{
		ft_putstr(data->fig[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int 				main()
{
	t_data			data;

//	ft_putstr(TEXT);
	set_data(&data);
	read_board(&data);
	print_fig_map(&data);
	return (0);
}
