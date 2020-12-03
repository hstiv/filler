/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <satmak335@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:48:40 by hstiv             #+#    #+#             */
/*   Updated: 2020/12/03 18:48:42 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 				read_player(t_data *data)
{
	char 			*c;
	int				ret;

	ret = 0;
	if (get_next_line(0, &data->line))
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
	int 			i;

	get_next_line(0, &data->line);
	s = ft_strsplit(data->line, ' ');
	free(data->line);
	len = ft_atoi(s[1]);
	data->fig = (char **)malloc(sizeof(char *) * len + 1);
	ft_arraydel((void **)s);
	free(s);
	data->fig[len] = NULL;
	i = 0;
	while (i < len)
	{
		get_next_line(0, &data->line);
		data->fig[i] = ft_strdup(data->line);
		free(data->line);
		i++;
	}
}

static void 		create_map(t_data *data)
{
	char 			**s;
	int				i;

	get_next_line(0, &data->line);
	i = 0;
	s = ft_strsplit(data->line, ' ');
	free(data->line);
	data->x = ft_atoi(s[1]);
	data->y = ft_atoi(s[2]);
	ft_arraydel((void **)s);
	free(s);
	data->map = (char **)malloc(sizeof(char *) * data->x + 1);
	data->hmap = (int **)malloc(sizeof(int *) * data->x + 1);
	while (i < data->x)
	{
		data->hmap[i] = (int *)malloc(sizeof(int) * data->y);
		data->map[i++] = (char *)malloc(sizeof(char) * data->y);
	}
	data->map[i] = NULL;
}

static void 		read_map(t_data *data)
{
	char			**s;
	int 			i;

	if (data->map == NULL)
		create_map(data);
	i = 0;
	while (i < data->x && get_next_line(0, &data->line) != 1)
	{
		s = ft_strsplit(data->line, ' ');
		if (ft_strlen2(s) != 2)
		{
			ft_arraydel((void **)s);
			ft_arraydel((void **)data->line);
			free(s);
			free(data->line);
			continue;
		}
		if (i != ft_atoi(s[0]))
			exit(-1);
		data->map[i] = ft_strcpylower(data->map[i], s[1]);
		ft_arraydel((void **)s);
		free(s);
		free(data->line);
		data->line = NULL;
		i++;
	}
}

int 				read_board(t_data *data)
{
	read_map(data);
	read_figure(data);
	return (1);
}
