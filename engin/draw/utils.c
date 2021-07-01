/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:00:03 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:35:43 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_chrflbuff(t_data *d, t_plspr *p, int y)
{
	int	*sprite;

	sprite = d->dspr.t_spr;
	p->de = y * 256 - d->conf->winsz->win_h * 128 + p->spr_height * 128;
	p->tex_y = ((p->de * TEX_HEIGHT) / p->spr_height) / 256;
	p->color = sprite[TEX_WIDTH * p->tex_y + p->tex_x];
}
