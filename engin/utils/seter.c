/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:29:58 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 14:53:50 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_txtur(int ***txturs, t_data *d, char **p)
{
	int	w;
	int	h;
	int	i;
	int	*txtur;

	i = 0;
	w = 64;
	h = 64;
	*txturs = malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		d->data_img[i].img = mlx_xpm_file_to_image(d->mlx, p[i], &w, &h);
		if (!d->data_img[i].img)
			return (0);
		d->data_img[i].addr = mlx_get_data_addr(d->data_img[i].img, \
										&d->data_img[i].bits_per_pixel, \
										&d->data_img[i].line_length, \
										&d->data_img[i].endian);
		if (!d->data_img[i].addr)
			return (0);
		txtur = (int *)d->data_img[i].addr;
		(*txturs)[i] = txtur;
		i++;
	}
	return (1);
}

void	set_spr(t_data *d, char *path)
{
	int			w;
	int			h;
	t_tmpimg	t;

	w = 64;
	h = 64;
	t.img = mlx_xpm_file_to_image(d->mlx, path, &w, &h);
	if (!t.img)
	{
		msgerr(-8);
		frcnf(d->conf);
		exit(0);
	}
	t.addr = mlx_get_data_addr(t.img, &t.bits_per_pixel, \
								&t.line_length, &t.endian);
	d->dspr.t_spr = (int *)t.addr;
}

void	set_arr(int ***p, int w, int h)
{
	int	i;
	int	j;
	int	**arr;

	arr = malloc(sizeof(int *) * h);
	i = 0;
	while (i < h)
	{
		j = 0;
		arr[i] = malloc(sizeof(int) * w);
		while (j < w)
			arr[i][j++] = 0;
		i++;
	}
	*p = arr;
}
