/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:55:45 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/10 10:32:28 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	chkln(char *s)
{
	int	i;

	i = skip_space(s) - 1;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '1')
			return (0);
	return (1);
}

int	chkbrd(char *s)
{
	int	i;

	i = skip_space(s);
	if (s[i] != '1')
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ')
		i--;
	if (s[i] != '1')
		return (0);
	return (1);
}

int	chkmap1(t_conf *conf)
{
	char	**map;
	t_itdar	itr;

	map = conf->map->arr;
	itr.i = -1;
	conf->map->cnt_h = 0;
	while (++itr.i < conf->map->h)
	{
		itr.j = -1;
		while (map[itr.i][++itr.j])
		{
			if (!ft_strchr("WSEN012 ", map[itr.i][itr.j]))
				return (0);
			if (ft_strchr("WSEN", map[itr.i][itr.j]))
				conf->map->cnt_h++;
		}
	}
	if (conf->map->cnt_h != 1)
		return (0);
	return (1);
}

int	chkmap(char **map, int h, int max)
{
	t_itdar	it;

	it.i = -1;
	if (max > 100)
		return (0);
	while (++it.i < h)
	{
		it.j = -1;
		while (++it.j < max)
		{
			if (map[it.i][it.j] == '0' || map[it.i][it.j] == '2' || \
				ft_strchr("SNWE", map[it.i][it.j]))
				if (!chkarnd(map, max, h, it))
					return (0);
		}
	}
	return (1);
}

void	flmap(t_conf *conf, char **map, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < conf->map->h)
	{
		map[i] = malloc(sizeof(char) * max);
		j = 0;
		while (j < (int)ft_strlen(conf->map->arr[i]))
		{
			map[i][j] = conf->map->arr[i][j];
			j++;
		}
		if (max > (int)ft_strlen(conf->map->arr[i]))
			while (j < max)
				map[i][j++] = ' ';
		map[i][j] = '\0';
		i++;
	}
}
