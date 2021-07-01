/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:34:09 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 14:52:56 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprdist(t_data *d)
{
	int		*ord;
	int		i;
	float	*dist;
	float	xx;
	float	yy;

	i = 0;
	ord = malloc(sizeof(int) * d->dspr.cnt);
	dist = malloc(sizeof(int) * d->dspr.cnt);
	while (i < d->dspr.cnt)
	{
		ord[i] = i;
		xx = fabs(d->dspr.spr[i].x - d->plr->pos_y);
		yy = fabs(d->dspr.spr[i].y - d->plr->pos_x);
		dist[i] = sqrt(xx * xx + yy * yy);
		i++;
	}
	if (d->dspr.spr_dist)
		free(d->dspr.spr_dist);
	if (d->dspr.spr_ord)
		free(d->dspr.spr_ord);
	d->dspr.spr_dist = dist;
	d->dspr.spr_ord = ord;
}

static int	cntspr(t_data *d)
{
	char	**map;
	int		i;
	int		j;
	int		cnt;

	i = 0;
	cnt = 0;
	map = d->conf->map->arr;
	while (i < d->conf->map->h)
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == '2')
				cnt++;
		i++;
	}
	return (cnt);
}

int	init_sprites(t_data *d)
{
	int			cnt;
	int			m;
	t_sprarr	*spr;
	t_itdar		it;

	cnt = cntspr(d);
	it.i = -1;
	m = 0;
	spr = malloc(sizeof(t_sprarr) * cnt);
	while (++it.i < d->conf->map->h)
	{
		it.j = -1;
		while (d->conf->map->arr[it.i][++it.j])
		{
			if (d->conf->map->arr[it.i][it.j] == '2')
			{
				spr[m].x = it.j + 0.5;
				spr[m].y = it.i + 0.5;
				m++;
			}
		}
	}
	d->dspr.spr = spr;
	d->dspr.cnt = cnt;
	return (1);
}
