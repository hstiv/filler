//
// Created by Hallie Stiv on 11/26/20.
//

#include "filler.h"

void 				set_data(t_data *data)
{
	data->player = 79;
	data->map = NULL;
	data->fig = NULL;
	data->line = NULL;
}

char				*ft_strcpymap(char *dst, char const *src, char (*f)(char))
{
	int				i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = (*f)(src[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
