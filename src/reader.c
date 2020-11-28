//
// Created by Hallie Stiv on 11/26/20.
//

#include "filler.h"

static void 		read_player(t_data *data)
{
	char 			*c;

	while (get_next_line(0, &data->line) && data->line != NULL)
	{
		if (ft_strstr(data->line, "hstiv") && ft_strstr(data->line, "exec"))
		{
			c = ft_strchr(data->line, 'p') + 1;
			data->player = (*c == '1') ? 'O' : 'X';
		}
		free(data->line);
	}
	data->is_first_round = 0;
}

static void 		read_figure(t_data *data)
{
	char 			**s;
	int				len;

	s = ft_strsplit(data->line, ' ');
	free(data->line);
	len = ft_atoi(s[1]);
	data->fig = (char **)malloc(sizeof(char *) * len);
	ft_arraydel((void **)s);
	free(s);
	while (len--)
	{
		get_next_line(0, &data->line);
		data->fig[len] = ft_strcpy(data->fig[len], data->line);
		free(data->line);
	}
}

static void 		create_map(t_data *data)
{
	char 			**s;
	int				i;
	int 			x;
	int 			y;

	i = 0;
	s = ft_strsplit(data->line, ' ');
	free(data->line);
	x = ft_atoi(s[1]);
	y = ft_atoi(s[2]);
	ft_arraydel((void **)s);
	free(s);
	data->map = (char **)malloc(sizeof(char *) * x);
	while (i < x)
		data->map[i++] = (char *)malloc(sizeof(char *) * y);
	data->map[x] = NULL;
}

static void 		read_map(t_data *data)
{
	char			**s;
	int 			x;

	while (get_next_line(0, &data->line) && !ft_strstr(data->line, "Plateau") && data->line != NULL)
		free(data->line);
	data->map == NULL ? create_map(data) : 0;
	get_next_line(0, &data->line);
	free(data->line);
	while(get_next_line(0, &data->line) && data->line != NULL)
	{
		if (ft_strstr(data->line, "Piece"))
			return ;
		s = ft_strsplit(data->line, ' ');
		x = ft_atoi(s[0]);
		data->map[x] = ft_strcpy(data->map[x], s[1]);
		ft_arraydel((void **)s);
		free(s);
		free(data->line);
		data->line = NULL;
	}
}

int 				read_board(t_data *data)
{
	if (data->is_first_round)
		read_player(data);
	read_map(data);
	if (data->line != NULL)
		read_figure(data);
	return (1);
}