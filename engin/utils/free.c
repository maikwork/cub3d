/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:30:37 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 14:45:07 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	frmap(void ***d, int h)
{
	int	i;

	i = 0;
	while (i < h && (*d)[i])
	{
		free((*d)[i]);
		i++;
	}
	free(*d);
	*d = NULL;
	return (1);
}

int	frcnf(t_conf *conf)
{
	free(conf->winsz);
	free(conf->clrs);
	if (conf->txturs->t_ea)
		free(conf->txturs->t_ea);
	if (conf->txturs->t_so)
		free(conf->txturs->t_so);
	if (conf->txturs->t_no)
		free(conf->txturs->t_no);
	if (conf->txturs->t_we)
		free(conf->txturs->t_we);
	if (conf->txturs->t_spr)
		free(conf->txturs->t_spr);
	frmap((void ***)&conf->map->arr, conf->map->h);
	free(conf->map);
	free(conf);
	return (1);
}

int	frimg(t_data *d)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(d->data_img[i].addr);
		free(d->data_img[i].img);
		i++;
	}
	free(d->data_img);
	return (1);
}

int	frgame(t_data *d)
{
	free(d->plr);
	frmap((void ***)&d->game.buffer, d->conf->winsz->win_h);
	free(d->game.zbuffer);
	return (1);
}

int	frall(t_data *d)
{
	frgame(d);
	frimg(d);
	frcnf(d->conf);
	free(d->mlx);
	free(d->img);
	free(d->addr);
	return (1);
}
