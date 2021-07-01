/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:24:31 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:31:49 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_clear(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->conf->winsz->win_h)
	{
		j = 0;
		while (j < d->conf->winsz->win_w)
		{
			d->game.buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	drawbuff(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->conf->winsz->win_h)
	{
		j = 0;
		while (j < d->conf->winsz->win_w)
		{
			my_mlx_pixel_put(d, j, i, d->game.buffer[i][j]);
			j++;
		}
		i++;
	}
	if (!d->save)
		mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	draw_3d(t_data *d)
{
	draw_clear(d);
	draw_fc(d);
	draw_txturs(d);
	init_sprdist(d);
	sort_spr(d);
	draw_spr(d);
	drawbuff(d);
}
