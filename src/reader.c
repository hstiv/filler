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
	if (get_next_line(0, &data->line) != 0)
	{
		if (ft_strstr(data->line, "hstiv.filler") && ft_strstr(data->line, "exec"))
		{
			c = ft_strchr(data->line, 'p') + 1;
			data->player = (*c == '1') ? 'o' : 'x';
			data->enemy = (data->player == 'o') ? 'x' : 'o';
			ret = 1;
		}
		ft_memdel((void **)&data->line);
	}
	return (ret);
}

static void 		read_figure(t_data *data)
{
	char 			**s;
	int 			i;

	get_next_line(0, &data->line);
	s = ft_strsplit(data->line, ' ');
	ft_memdel((void **)&data->line);
	data->fsize[0] = ft_atoi(s[1]);
	data->fsize[1] = ft_atoi(s[2]);
	data->fig = (char **)malloc(sizeof(char *) * data->fsize[0] + 1);
	ft_arraydel((void **)s);
	free(s);
	i = 0;
	while (i < data->fsize[0])
	{
		get_next_line(0, &data->line);
		data->fig[i] = ft_strdup(data->line);
		ft_memdel((void **)&data->line);
		i++;
	}
	data->fig[i] = NULL;
}

static void 		create_map(t_data *data)
{
	char 			**s;
	int				i;

	get_next_line(0, &data->line);
	s = ft_strsplit(data->line, ' ');
	ft_memdel((void **)&data->line);
	data->msize[0] = ft_atoi(s[1]);
	data->msize[1] = ft_atoi(s[2]);
	ft_arraydel((void **)s);
	free(s);
	data->map = (char **)malloc(sizeof(char *) * data->msize[0] + 1);
	data->hmap = (int **)malloc(sizeof(int *) * data->msize[0] + 1);
	i = 0;
	while (i < data->msize[0])
	{
		data->hmap[i] = (int *)malloc(sizeof(int) * data->msize[1]);
		data->map[i] = (char *)malloc(sizeof(char) * data->msize[1]);
		i++;
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
	while (i < data->msize[0] && get_next_line(0, &data->line))
	{
		s = ft_strsplit(data->line, ' ');
		if (ft_strlen2(s) != 2)
		{
			ft_arraydel((void **)s);
			free(s);
			ft_memdel((void **)&data->line);
			continue;
		}
		if (i != ft_atoi(s[0]))
			throw("BAD_EXCESS\n");
		data->map[i] = ft_strcpylower(data->map[i], s[1]);
		ft_arraydel((void **)s);
		free(s);
		ft_memdel((void **)&data->line);
		i++;
	}
}

int 				read_board(t_data *data)
{
	read_map(data);
	read_figure(data);
	return (1);
}
