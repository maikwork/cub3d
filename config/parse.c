/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:23:56 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/12 09:22:04 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	prsdsp(t_conf *conf, char *s)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	if (!chknbr(conf, &s[i], 2))
		return (0);
	while (s[i])
	{
		i += skip_space(&s[i]);
		if (!cnt && ++cnt)
			conf->winsz->win_w = ft_atoi(&s[i]);
		else if (s[i] && cnt == 1)
			conf->winsz->win_h = ft_atoi(&s[i]);
		if (s[i] == ',')
			return ((conf->err = -1 ) && 0);
		i += skip_digit(&s[i]);
	}
	return (1);
}

int	prsmap(t_conf *conf, char *s)
{
	int			i;
	static int	itr;

	i = 0;
	while (s[i] && ft_strchr("012NSWE", s[i]))
		i++;
	if (!is_validchr(s[i]))
		return ((conf->err = -5) && 0);
	conf->map->arr[itr] = ft_strdup(s);
	if (!chkbrd(conf->map->arr[itr]))
		return ((conf->err = -5) && 0);
	if ((itr == 0 || itr == conf->map->h - 1) && \
			!chkln(conf->map->arr[itr]))
		return ((conf->err = -5) && 0);
	itr++;
	return (1);
}

int	prstxturs(t_conf *conf, char *s)
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strchr("NOSWEA", s[i]))
		i++;
	i = trnopr_i(!skip_space(&s[i]), 0, i + skip_space(&s[i]));
	path = ft_strdup(&s[i]);
	if (!i || !chkpath(conf, path))
		return (0);
	if (s[0] == 'S' && s[1] == 'O')
		conf->txturs->t_so = path;
	else if (s[0] == 'N' && s[1] == 'O')
		conf->txturs->t_no = path;
	else if (s[0] == 'W' && s[1] == 'E')
		conf->txturs->t_we = path;
	else if (s[0] == 'E' && s[1] == 'A')
		conf->txturs->t_ea = path;
	else if (s[0] == 'S' && s[1] == ' ')
		conf->txturs->t_spr = path;
	return (1);
}

int	prsclr(t_conf *conf, char *s)
{
	int	i;
	int	j;
	int	*nbr;

	i = 1;
	if (s[0] == 'F')
		nbr = &conf->clrs->clr_f;
	if (s[0] == 'C')
		nbr = &conf->clrs->clr_c;
	if (!chknbr(conf, &s[i], 3))
		return (0);
	*nbr = 0 << 24;
	j = 16;
	i += skip_space(&s[i]);
	while (s[i])
		if (setclr(s, &i, &j, nbr) < 0)
			return (((conf->err = -2) && 0));
	return (1);
}
