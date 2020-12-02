//
// Created by Hallie Stiv on 11/26/20.
//

#include "filler.h"

int 				read_player(t_data *data)
{
	char 			*c;
	int				ret;

	ret = 0;
	if (get_next_line(0, &data->line) != 0)
	{
		if (ft_strstr(data->line, "hstiv.filler") && ft_strstr(data->line, "exec"))
		{
			c = ft_strchr(data->line, 'p') + 1;
			data->player = (*c == '1') ? 'o' : 'x';
			data->enemy = (data->player == 'o') ? 'x' : 'o';
			ret = 1;
		}
		free(data->line);
	}
	return (ret);
}

static void 		read_figure(t_data *data)
{
	char 			**s;
	int				len;

	if (get_next_line(0, &data->line) == 1)
		exit(-1);
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

	if (get_next_line(0, &data->line) == 1)
		exit(-1);
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

	data->map == NULL ? create_map(data) : 0;
	while (get_next_line(0, &data->line) != 1)
	{
		if ((s = ft_strsplit(data->line, ' '))[1] == NULL)
		{
			ft_arraydel(s);
			free(s);
			free(data->line);
			continue ;
		}
		s = ft_strsplit(data->line, ' ');
		x = ft_atoi(s[0]);
		data->map[x] = ft_strcpymap(data->map[x], s[1], ft_tolower);
		ft_arraydel((void **)s);
		free(s);
		free(data->line);
		data->line = NULL;
	}
}

int 				read_board(t_data *data)
{
	read_map(data);
	read_figure(data);
	return (1);
}