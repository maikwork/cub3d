/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:44:54 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:34:00 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	push_swap(t_data *d, int j)
{
	int		tmp_order;
	float	tmp_dist;

	tmp_order = d->dspr.spr_ord[j];
	d->dspr.spr_ord[j] = d->dspr.spr_ord[j + 1];
	d->dspr.spr_ord[j + 1] = tmp_order;
	tmp_dist = d->dspr.spr_dist[j];
	d->dspr.spr_dist[j] = d->dspr.spr_dist[j + 1];
	d->dspr.spr_dist[j + 1] = tmp_dist;
}

void	sort_spr(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < d->dspr.cnt)
	{
		j = 0;
		while (j + 1 < d->dspr.cnt)
		{
			if (d->plr->dir_x <= 0 || \
				d->plr->plane_y <= 0 || \
				(int)(d->plr->dir_x - d->plr->plane_y) == 0)
			{
				if (d->dspr.spr_dist[j] < d->dspr.spr_dist[j + 1])
					push_swap(d, j);
			}
			else
			{
				if (d->dspr.spr_dist[j] > d->dspr.spr_dist[j + 1])
					push_swap(d, j);
			}
			j++;
		}
		i++;
	}
}

static void	init_start(t_data *d, t_plspr *p, int i)
{
	p->sprite_x = d->dspr.spr[d->dspr.spr_ord[i]].y - d->plr->pos_x;
	p->sprite_y = d->dspr.spr[d->dspr.spr_ord[i]].x - d->plr->pos_y;
	p->inv_det = 1.0 / (d->plr->plane_x * d->plr->dir_y - \
						d->plr->dir_x * d->plr->plane_y);
	p->transf_x = p->inv_det * (d->plr->dir_y * p->sprite_x - \
								d->plr->dir_x * p->sprite_y);
	p->transf_y = p->inv_det * (-d->plr->plane_y * p->sprite_x + \
								d->plr->plane_x * p->sprite_y);
	p->spr_scr_x = (int)((d->conf->winsz->win_w / 2) * \
						(1 + p->transf_x / p->transf_y));
	p->spr_height = abs((int)(d->conf->winsz->win_h / (p->transf_y)));
	p->draw_start_y = -p->spr_height / 2 + d->conf->winsz->win_h / 2;
}

static void	fill_buff(t_data *d, t_plspr *p)
{
	int	*sprite;
	int	stripe;
	int	y;

	sprite = d->dspr.t_spr;
	stripe = p->draw_start_x - 1;
	while (++stripe < p->draw_end_x)
	{
		p->tex_x = (int)(256 * (stripe - (-p->sprite_width / \
					2 + p->spr_scr_x)) * TEX_WIDTH / p->sprite_width) / 256;
		if (p->transf_y > 0 && stripe > 0 && \
			stripe < d->conf->winsz->win_w && \
			p->transf_y < d->game.zbuffer[stripe])
		{
			y = p->draw_start_y - 1;
			while (++y < p->draw_end_y)
			{
				init_chrflbuff(d, p, y);
				if ((p->color & 0x00FFFFFF) != 0)
					d->game.buffer[y][stripe] = p->color;
			}
		}
	}
}

void	draw_spr(t_data *d)
{
	t_plspr	p;
	int		i;

	i = 0;
	while (i < d->dspr.cnt)
	{
		init_start(d, &p, i);
		if (p.draw_start_y < 0)
			p.draw_start_y = 0;
		p.draw_end_y = p.spr_height / 2 + d->conf->winsz->win_h / 2;
		if (p.draw_end_y >= d->conf->winsz->win_h)
			p.draw_end_y = d->conf->winsz->win_h - 1;
		p.sprite_width = abs((int)(d->conf->winsz->win_h / (p.transf_y)));
		p.draw_start_x = -p.sprite_width / 2 + p.spr_scr_x;
		if (p.draw_start_x < 0)
			p.draw_start_x = 0;
		p.draw_end_x = p.sprite_width / 2 + p.spr_scr_x;
		if (p.draw_end_x >= d->conf->winsz->win_w)
			p.draw_end_x = d->conf->winsz->win_w - 1;
		fill_buff(d, &p);
		i++;
	}
}
