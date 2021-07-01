/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txturs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:24:51 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:34:55 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dist(t_play *play, float pos_x, float pos_y)
{
	if (play->ray_dir_x < 0)
	{
		play->step_x = -1;
		play->side_dist_x = (pos_x - play->map_x) * play->delta_dist_x;
	}
	else
	{
		play->step_x = 1;
		play->side_dist_x = (play->map_x + 1.0 - pos_x) * play->delta_dist_x;
	}
	if (play->ray_dir_y < 0)
	{
		play->step_y = -1;
		play->side_dist_y = (pos_y - play->map_y) * play->delta_dist_y;
	}
	else
	{
		play->step_y = 1;
		play->side_dist_y = (play->map_y + 1.0 - pos_y) * play->delta_dist_y;
	}
}

static void	fnd_wall(t_play *play, char **arr)
{
	while (1)
	{
		if (play->side_dist_x < play->side_dist_y)
		{
			play->side_dist_x += play->delta_dist_x;
			play->map_x += play->step_x;
			play->side = 0;
		}
		else
		{
			play->side_dist_y += play->delta_dist_y;
			play->map_y += play->step_y;
			play->side = 1;
		}
		if (arr[play->map_x][play->map_y] == '1')
			break ;
	}
}

static void	init_start(t_play *play, t_data *d, int x)
{
	play->camera_x = 2 * x / (double)d->conf->winsz->win_w - 1;
	play->ray_dir_y = d->plr->dir_y + d->plr->plane_y * play->camera_x;
	play->ray_dir_x = d->plr->dir_x + d->plr->plane_x * play->camera_x;
	play->map_x = (int)(d->plr->pos_x);
	play->map_y = (int)(d->plr->pos_y);
	play->delta_dist_x = fabs(1 / play->ray_dir_x);
	play->delta_dist_y = fabs(1 / play->ray_dir_y);
}

static void	fill_buff(t_play *play, t_data *d, int x)
{
	int	y;

	y = play->draw_start;
	while (y < play->draw_end)
	{
		play->tex_y = (int)play->tex_pos & (TEX_HEIGHT - 1);
		play->tex_pos += play->step;
		if (play->side == 0 && play->ray_dir_x >= 0)
			play->color = d->txturs[0][TEX_HEIGHT * play->tex_y + play->tex_x];
		else if (play->side == 0 && play->ray_dir_x < 0)
			play->color = d->txturs[1][TEX_HEIGHT * play->tex_y + play->tex_x];
		else if (play->side == 1 && play->ray_dir_y > 0)
			play->color = d->txturs[2][TEX_HEIGHT * play->tex_y + play->tex_x];
		else
			play->color = d->txturs[3][TEX_HEIGHT * play->tex_y + play->tex_x];
		if (play->side == 1)
			play->color = (play->color >> 1) & 8355711;
		d->game.buffer[y][x] = play->color;
		y++;
	}
}

void	draw_txturs(t_data *d)
{
	int		x;
	t_play	play;

	x = 0;
	while (x < d->conf->winsz->win_w)
	{
		init_start(&play, d, x);
		set_dist(&play, d->plr->pos_x, d->plr->pos_y);
		fnd_wall(&play, d->conf->map->arr);
		fnd_perp(&play, d);
		set_range(&play, d);
		fnd_txtpos(&play, d);
		fill_buff(&play, d, x);
		d->game.zbuffer[x] = play.perp_wall_dist;
		x++;
	}
}
