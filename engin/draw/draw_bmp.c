/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:15:45 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:32:17 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_bmp(t_bmp bmp, t_data *d, int fd)
{
	int	y;

	write(fd, bmp.file.type, 2);
	write(fd, &bmp.file.size, 4);
	write(fd, &bmp.file.reserved, 4);
	write(fd, &bmp.file.offset, 4);
	write(fd, &bmp.info.size, 4);
	write(fd, &bmp.info.width, 4);
	write(fd, &bmp.info.height, 4);
	write(fd, &bmp.info.planes, 2);
	write(fd, &bmp.info.bpp, 2);
	write(fd, &bmp.info.compression, 4);
	write(fd, &bmp.info.image_size, 4);
	write(fd, &bmp.info.x_pixel, 4);
	write(fd, &bmp.info.y_pixel, 4);
	write(fd, &bmp.info.total_color, 4);
	write(fd, &bmp.info.important_color, 4);
	y = bmp.info.height - 1;
	while (y >= 0)
	{
		write(fd, &d->addr[y * d->line_length], d->line_length);
		y--;
	}
}

void	init_bmp(t_bmp *bmp, t_data *d)
{
	bmp->file.type = "BM";
	bmp->file.size = d->conf->winsz->win_w * d->conf->winsz->win_h;
	bmp->file.reserved = 0;
	bmp->file.offset = 14 + 40;
	bmp->info.size = 40;
	bmp->info.width = d->conf->winsz->win_w;
	bmp->info.height = d->conf->winsz->win_h;
	bmp->info.planes = 1;
	bmp->info.bpp = d->bits_per_pixel;
	bmp->info.compression = 0;
	bmp->info.image_size = 0;
	bmp->info.x_pixel = 0;
	bmp->info.y_pixel = 0;
	bmp->info.total_color = 0;
	bmp->info.important_color = 0;
}
