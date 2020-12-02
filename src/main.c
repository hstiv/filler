//
// Created by Hallie Stiv on 11/26/20.
//
#include "filler.h"
#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int 				main(void)
{
	t_data			data;
	char			*line;

	set_data(&data);
	if (!read_player(&data))
		exit(-1);
	while (read_board(&data))
	{
		
	}
	return (0);
}
