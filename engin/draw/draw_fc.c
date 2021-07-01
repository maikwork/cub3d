/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:24:40 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:32:47 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_buff(t_data *d, t_plfc *p, int y)
{
	int	x;

	x = 0;
	while (x < d->conf->winsz->win_w)
	{
		p->cell_x = (int)(p->floor_x);
		p->cell_y = (int)(p->floor_y);
		p->floor_x += p->floor_step_x;
		p->floor_y += p->floor_step_y;
		p->color = d->conf->clrs->clr_f;
		d->game.buffer[y][x] = p->color;
		p->color = d->conf->clrs->clr_c;
		d->game.buffer[d->conf->winsz->win_h - y - 1][x] = p->color;
		x++;
	}
}

void	draw_fc(t_data *d)
{
	t_plfc	p;
	int		y;

	y = 0;
	while (y < d->conf->winsz->win_h)
	{
		p.ray_dir_x0 = d->plr->dir_x - d->plr->plane_x;
		p.ray_dir_y0 = d->plr->dir_y - d->plr->plane_y;
		p.ray_dir_x1 = d->plr->dir_x + d->plr->plane_x;
		p.ray_dir_y1 = d->plr->dir_y + d->plr->plane_y;
		p.p = y - d->conf->winsz->win_h / 2;
		p.pos_z = 0.5 * d->conf->winsz->win_h;
		p.row_dist = p.pos_z / p.p;
		p.floor_step_x = p.row_dist * (p.ray_dir_x1 - p.ray_dir_x0) \
										/ d->conf->winsz->win_w;
		p.floor_step_y = p.row_dist * (p.ray_dir_y1 - p.ray_dir_y0) \
										/ d->conf->winsz->win_w;
		p.floor_x = d->plr->pos_x + p.row_dist * p.ray_dir_x0;
		p.floor_y = d->plr->pos_y + p.row_dist * p.ray_dir_y0;
		fill_buff(d, &p, y);
		y++;
	}
}
