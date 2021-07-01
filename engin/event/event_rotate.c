/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:56:02 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:43:43 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rtleft(t_data *d)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = d->plr->dir_x;
	old_plane_x = d->plr->plane_x;
	d->plr->dir_x = d->plr->dir_x * cos(d->plr->rtspd) - \
					d->plr->dir_y * sin(d->plr->rtspd);
	d->plr->dir_y = old_dir_x * sin(d->plr->rtspd) + \
					d->plr->dir_y * cos(d->plr->rtspd);
	d->plr->plane_x = d->plr->plane_x * cos(d->plr->rtspd) - \
					d->plr->plane_y * sin(d->plr->rtspd);
	d->plr->plane_y = old_plane_x * sin(d->plr->rtspd) + \
					d->plr->plane_y * cos(d->plr->rtspd);
}

void	rtright(t_data *d)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = d->plr->dir_x;
	old_plane_x = d->plr->plane_x;
	d->plr->dir_x = d->plr->dir_x * cos(-d->plr->rtspd) - \
					d->plr->dir_y * sin(-d->plr->rtspd);
	d->plr->dir_y = old_dir_x * sin(-d->plr->rtspd) + \
					d->plr->dir_y * cos(-d->plr->rtspd);
	d->plr->plane_x = d->plr->plane_x * cos(-d->plr->rtspd) - \
					d->plr->plane_y * sin(-d->plr->rtspd);
	d->plr->plane_y = old_plane_x * sin(-d->plr->rtspd) + \
					d->plr->plane_y * cos(-d->plr->rtspd);
}
