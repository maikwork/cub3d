/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txturs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:25:03 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/08 09:11:13 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fnd_txtpos(t_play *play, t_data *d)
{
	if (play->side == 0)
		play->wall_x = d->plr->pos_y + play->perp_wall_dist * play->ray_dir_y;
	else
		play->wall_x = d->plr->pos_x + play->perp_wall_dist * play->ray_dir_x;
	play->wall_x -= floor((play->wall_x));
	play->tex_x = (int)(play->wall_x * TEX_WIDTH);
	if (play->side == 0 && play->ray_dir_x > 0)
		play->tex_x = TEX_WIDTH - play->tex_x - 1;
	if (play->side == 1 && play->ray_dir_y < 0)
		play->tex_x = TEX_WIDTH - play->tex_x - 1;
	play->step = 1.0 * TEX_HEIGHT / play->line_height;
	play->tex_pos = (play->draw_start - d->conf->winsz->win_h / 2 + \
					play->line_height / 2) * play->step;
}

void	set_range(t_play *play, t_data *d)
{
	play->draw_start = -play->line_height / 2 + d->conf->winsz->win_h / 2;
	if (play->draw_start < 0)
		play->draw_start = 0;
	play->draw_end = play->line_height / 2 + d->conf->winsz->win_h / 2;
	if (play->draw_end >= d->conf->winsz->win_h)
		play->draw_end = d->conf->winsz->win_h - 1;
}

void	fnd_perp(t_play *play, t_data *d)
{
	if (play->side == 0)
		play->perp_wall_dist = (play->map_x - d->plr->pos_x + \
						(1 - play->step_x) / 2) / play->ray_dir_x;
	else
		play->perp_wall_dist = (play->map_y - d->plr->pos_y + \
						(1 - play->step_y) / 2) / play->ray_dir_y;
	play->line_height = (int)(d->conf->winsz->win_h / play->perp_wall_dist);
}
