/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:36:32 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 14:45:48 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setdir(t_plr *plr, int w, float x, float y)
{
	if (w == 1)
	{
		plr->dir_x = x;
		plr->dir_y = y;
	}
	else
	{
		plr->plane_x = x;
		plr->plane_y = y;
	}
}

static void	set_plr(t_plr *plr, char c)
{
	if (c == 'W')
	{
		setdir(plr, 1, 0.0, -1.0);
		setdir(plr, 2, -0.66, 0.0);
	}
	else if (c == 'E')
	{
		setdir(plr, 1, 0.0, 1.0);
		setdir(plr, 2, 0.66, 0.0);
	}
	else if (c == 'N')
	{
		setdir(plr, 1, -1.0, 0.0);
		setdir(plr, 2, 0.0, 0.66);
	}
	else if (c == 'S')
	{
		setdir(plr, 1, 1.0, 0.0);
		setdir(plr, 2, 0.0, -0.66);
	}
}

void	init_plr(t_data *d)
{
	t_plr	*plr;
	t_itdar	itr;

	plr = malloc(sizeof(t_plr));
	itr.i = -1;
	while (++itr.i < d->conf->map->h)
	{
		itr.j = -1;
		while (d->conf->map->arr[itr.i][++itr.j])
		{
			if (ft_strchr("WENS", d->conf->map->arr[itr.i][itr.j]))
			{
				plr->pos_y = itr.j + .5;
				plr->pos_x = itr.i + .5;
				set_plr(plr, d->conf->map->arr[itr.i][itr.j]);
				d->conf->map->arr[itr.i][itr.j] = '0';
			}
		}
	}
	d->plr = plr;
}
