/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:18:32 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:36:36 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_data *d)
{
	frall(d);
	free(d->win);
	exit(0);
}

int	key_press(int key, t_data *d)
{
	d->plr->mvspd = d->conf->winsz->win_h * \
					d->conf->winsz->win_w / (double)9000000;
	d->plr->rtspd = d->conf->winsz->win_h * \
					d->conf->winsz->win_w / (double)10000000;
	if (key == KEY_EXIT)
		ft_exit(d);
	if (key == KEY_W)
		mvtop(d);
	if (key == KEY_S)
		mvdown(d);
	if (key == KEY_D)
		mvright(d);
	if (key == KEY_A)
		mvleft(d);
	if (key == KEY_LEFT)
		rtleft(d);
	if (key == KEY_RIGHT)
		rtright(d);
	draw_3d(d);
	return (1);
}
