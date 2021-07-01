/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:23:18 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/12 09:21:40 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_chrcnf(t_chrconf *chrconf, char *line)
{
	int	i;

	i = skip_space(line);
	if (!line[i])
		return (2);
	if (!chrconf->r && line[i] == 'R' && line[i + 1] == ' ')
		return (chrconf->r = 1);
	else if (!chrconf->so && line[i] == 'S' && line[i + 1] == 'O')
		return (chrconf->so = 1);
	else if (!chrconf->no && line[i] == 'N' && line[i + 1] == 'O')
		return (chrconf->no = 1);
	else if (!chrconf->we && line[i] == 'W' && line[i + 1] == 'E')
		return (chrconf->we = 1);
	else if (!chrconf->ea && line[i] == 'E' && line[i + 1] == 'A')
		return (chrconf->ea = 1);
	else if (!chrconf->spr && line[i] == 'S' && line[i + 1] == ' ')
		return (chrconf->spr = 1);
	else if (!chrconf->f && line[i] == 'F' && line[i + 1] == ' ')
		return (chrconf->f = 1);
	else if (!chrconf->c && line[i] == 'C' && line[i + 1] == ' ')
		return (chrconf->c = 1);
	else if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	check_flcnf(t_chrconf *chrcnf)
{
	if (chrcnf->c && chrcnf->f && \
		chrcnf->r && chrcnf->spr && \
		chrcnf->so && chrcnf->no && \
		chrcnf->ea && chrcnf->we)
		return (1);
	return (0);
}

int	chkpath(t_conf *conf, char *s)
{
	int			i;
	int			fd;
	int			len;
	const char	*s2 = ".xpm";

	if (!s || s[0] == '\0')
		return ((conf->err = -4) && 0);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return ((conf->err = -4) && 0);
	close(fd);
	len = ft_strlen(s);
	i = 0;
	while (s[len - i] != '.')
	{
		if (s[len - i] != s2[ft_strlen(s2) - i])
			return ((conf->err = -4) && 0);
		i++;
	}
	return (1);
}

int	chknbr(t_conf *conf, char *s, int cnt)
{
	int	i;
	int	len;

	i = 0;
	while (s[i])
	{
		i += skip_space(&s[i]);
		if (s[i] == '-')
			return ((conf->err = -1) && 0);
		cnt -= trnopr_i(ft_isdigit(s[i]), 1, 0);
		i = trnopr_i(skip_digit(&s[i]) > 5, 0, i + skip_digit(&s[i]));
		if (s[i] == ',')
			i++;
		if (!i || !s[i] || (!ft_isdigit(s[i]) && s[i] != ' '))
			break ;
	}
	if (!i || s[i])
		return ((conf->err = -1) && 0);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ')
		len--;
	if ((s[len] && !ft_isdigit(s[len])) || cnt)
		return ((conf->err = -1) && 0);
	return (1);
}

int	check_map(t_conf *conf)
{
	char		**map;
	int			i;
	int			max;

	i = -1;
	max = 0;
	if (!chkmap1(conf))
		return (0);
	map = malloc(sizeof(char *) * conf->map->h);
	while (++i < conf->map->h)
		if (max < (int)ft_strlen(conf->map->arr[i]))
			max = (int)ft_strlen(conf->map->arr[i]);
	flmap(conf, map, max);
	if (!chkmap(map, conf->map->h, max) || \
		!frmap((void ***)&map, conf->map->h))
		return (0);
	return (1);
}
