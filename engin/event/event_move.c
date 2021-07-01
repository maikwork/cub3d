/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:24:34 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:42:55 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mvleft(t_data *d)
{
	float	offset;

	offset = d->plr->dir_y * d->plr->mvspd;
	if (d->conf->map->arr[(int)(d->plr->pos_x - offset)] \
		[(int)d->plr->pos_y] == '0')
		d->plr->pos_x -= offset;
	offset = d->plr->dir_x * d->plr->mvspd;
	if (d->conf->map->arr[(int)(d->plr->pos_x)] \
		[(int)(d->plr->pos_y + offset)] == '0')
		d->plr->pos_y += offset;
}

void	mvright(t_data *d)
{
	float	offset;

	offset = d->plr->dir_y * d->plr->mvspd;
	if (d->conf->map->arr[(int)(d->plr->pos_x + offset)] \
		[(int)d->plr->pos_y] == '0')
		d->plr->pos_x += offset;
	offset = d->plr->dir_x * d->plr->mvspd;
	if (d->conf->map->arr[(int)(d->plr->pos_x)] \
		[(int)(d->plr->pos_y - offset)] == '0')
		d->plr->pos_y -= offset;
}

void	mvtop(t_data *d)
{
	char	**map;

	map = d->conf->map->arr;
	if (map[(int)(d->plr->pos_x + d->plr->dir_x * d->plr->mvspd)] \
		[(int)(d->plr->pos_y)] == '0')
		d->plr->pos_x += d->plr->dir_x * d->plr->mvspd;
	if (map[(int)(d->plr->pos_x)] \
		[(int)(d->plr->pos_y + d->plr->dir_y * d->plr->mvspd)] == '0')
		d->plr->pos_y += d->plr->dir_y * d->plr->mvspd;
}

void	mvdown(t_data *d)
{
	char	**map;

	map = d->conf->map->arr;
	if (map[(int)(d->plr->pos_x - d->plr->dir_x * d->plr->mvspd)] \
		[(int)(d->plr->pos_y)] == '0')
		d->plr->pos_x -= d->plr->dir_x * d->plr->mvspd;
	if (map[(int)(d->plr->pos_x)] \
		[(int)(d->plr->pos_y - d->plr->dir_y * d->plr->mvspd)] == '0')
		d->plr->pos_y -= d->plr->dir_y * d->plr->mvspd;
}
