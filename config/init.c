/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:23:31 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/10 10:44:51 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	init_conf(t_conf *conf, char *path)
{
	int	i;

	i = 0;
	conf->err = 0;
	conf->map = malloc(sizeof(t_map));
	conf->map->h = srch_h(path);
	if (!conf->map->h || conf->map->h > 60)
		conf->err = -3;
	conf->map->arr = malloc(sizeof(char *) * conf->map->h);
	while (i < conf->map->h)
		conf->map->arr[i++] = NULL;
	conf->clrs = malloc(sizeof(t_clrs));
	conf->winsz = malloc(sizeof(t_winsz));
	conf->txturs = malloc(sizeof(t_txturs));
	conf->txturs->t_ea = NULL;
	conf->txturs->t_so = NULL;
	conf->txturs->t_we = NULL;
	conf->txturs->t_no = NULL;
	conf->txturs->t_spr = NULL;
	return (conf->map->h);
}

void	init_chrconf(t_chrconf *chrconf)
{
	chrconf->c = 0;
	chrconf->f = 0;
	chrconf->r = 0;
	chrconf->ea = 0;
	chrconf->no = 0;
	chrconf->so = 0;
	chrconf->we = 0;
	chrconf->spr = 0;
}
