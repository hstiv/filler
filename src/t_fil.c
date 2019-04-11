/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:21:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/31 17:46:26 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fil           *t_fil_new(void)
{
    t_fil       *fill;

    fill = malloc(sizeof(t_fil*) * 1);
    if (fill)
    {
        fill->data = 0;
        fill->map = NULL;
        fill->fig = 0;
    }
    return (fill);
}