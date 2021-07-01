/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:36:06 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 14:45:20 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_txtur(t_data *d)
{
	char	**path;
	int		**txtur;

	path = malloc(sizeof(char *) * 4);
	txtur = NULL;
	d->data_img = malloc(sizeof(t_img) * 4);
	path[2] = d->conf->txturs->t_ea;
	path[1] = d->conf->txturs->t_no;
	path[0] = d->conf->txturs->t_so;
	path[3] = d->conf->txturs->t_we;
	if (!set_txtur(&txtur, d, path))
	{
		msgerr(-8);
		frcnf(d->conf);
		exit(0);
	}
	free(d->txturs);
	free(path);
	d->txturs = txtur;
	return (1);
}

void	init_game(t_data *d, t_conf *conf)
{
	d->mlx = mlx_init();
	if (!d->save)
		d->win = mlx_new_window(d->mlx, conf->winsz->win_w, \
							conf->winsz->win_h, "Cub3d");
	d->conf = conf;
	d->dspr.spr_dist = NULL;
	d->dspr.spr_ord = NULL;
	init_plr(d);
	init_txtur(d);
	set_arr(&d->game.buffer, conf->winsz->win_w, conf->winsz->win_h);
	init_sprites(d);
	init_sprdist(d);
	set_spr(d, conf->txturs->t_spr);
	d->game.zbuffer = malloc(sizeof(double) * conf->winsz->win_w);
	d->img = mlx_new_image(d->mlx, conf->winsz->win_w, conf->winsz->win_h);
	d->addr = mlx_get_data_addr(d->img, \
				&d->bits_per_pixel, &d->line_length, &d->endian);
}
