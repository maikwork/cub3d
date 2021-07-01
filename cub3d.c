/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:45:02 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/12 09:38:11 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_bmp(t_data d, t_conf *conf)
{
	int		fd;
	t_bmp	bmp;

	d.save = 1;
	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	init_game(&d, conf);
	draw_3d(&d);
	init_bmp(&bmp, &d);
	write_bmp(bmp, &d, fd);
	frall(&d);
	return (0);
}

static int	start_game(t_data d, t_conf *conf)
{
	mlx_get_screen_size(d.mlx, &d.win_w, &d.win_h);
	if (conf->winsz->win_w > d.win_w)
		conf->winsz->win_w = d.win_w;
	if (conf->winsz->win_h > d.win_h)
		conf->winsz->win_h = d.win_h;
	if (conf->winsz->win_h < 300)
		conf->winsz->win_h = 300;
	if (conf->winsz->win_w < 400)
		conf->winsz->win_w = 400;
	init_game(&d, conf);
	draw_3d(&d);
	mlx_hook(d.win, 2, 1L << 0, key_press, &d);
	mlx_hook(d.win, 17, 1L << 17, ft_exit, &d);
	mlx_loop(d.mlx);
	return (0);
}

int	chkpcnf(char *path)
{
	int			fd;
	t_itdar		it;
	const char	*s = ".cub";

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	it.i = ft_strlen(path);
	it.j = ft_strlen(s) - 1;
	while (it.j > 0 && path[--it.i] == s[it.j])
		it.j--;
	if (it.j)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data		img;
	t_conf		*conf;
	const char	*sv = "--save";

	if (ac < 2 || !chkpcnf(av[1]))
		return (msgerr(-6));
	conf = malloc(sizeof(t_conf));
	if (!ft_parser(av[1], conf))
		return (!msgerr(conf->err) * frcnf(conf));
	img.save = 0;
	if (!conf->winsz->win_h || !conf->winsz->win_w)
		return (msgerr(-1) * frcnf(conf));
	if (ac > 2)
	{
		if (!ft_strncmp(av[2], sv, ft_strlen(sv)) && \
			ft_strlen(av[2]) == 6 && ac == 3)
			return (start_bmp(img, conf));
		else
			return (frcnf(conf) && msgerr(-7));
	}
	start_game(img, conf);
}
