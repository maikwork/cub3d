/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:23:35 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/12 09:39:18 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../gnl/get_next_line.h"
# include "../minilib/mlx.h"
# include <fcntl.h>
# include "math.h"
# include "../utils/libft.h"
# include "config.h"
# include "engin.h"

# define PI 3.141592
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_EXIT 53

# define ERR_NOT_VALID_STR -1
# define ERR_NOT_VALID_DIG -2
# define ERR_NOT_VALID_CNF -3
# define ERR_NOT_VALID_PTH -4
# define ERR_NOT_VALID_MAP -5

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_dspr
{
	t_sprarr	*spr;
	int			*spr_ord;
	float		*spr_dist;
	int			*t_spr;
	int			cnt;
}				t_dspr;

typedef struct s_game
{
	int			**buffer;
	float		*zbuffer;
}				t_game;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			win_w;
	int			win_h;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			save;
	int			err;
	int			**txturs;
	t_conf		*conf;
	t_plr		*plr;
	t_img		*data_img;
	t_dspr		dspr;
	t_game		game;
}				t_data;

int				key_press(int key, t_data *d);
int				ft_exit(t_data *d);
void			mvleft(t_data *d);
void			mvright(t_data *d);
void			mvtop(t_data *d);
void			mvdown(t_data *d);
void			rtleft(t_data *d);
void			rtright(t_data *d);
int				ft_exit(t_data *d);
int				key_press(int key, t_data *d);

void			draw_3d(t_data *d);

void			draw_fc(t_data *d);

void			write_bmp(t_bmp bmp, t_data *d, int fd);
void			init_bmp(t_bmp *bmp, t_data *d);

void			sort_spr(t_data *d);
void			draw_spr(t_data *d);

void			draw_txturs(t_data *d);
void			fnd_txtpos(t_play *play, t_data *d);
void			set_range(t_play *play, t_data *d);
void			fnd_perp(t_play *play, t_data *d);
void			init_chrflbuff(t_data *d, t_plspr *p, int y);

int				frmap(void ***d, int h);
int				frcnf(t_conf *conf);
int				frimg(t_data *d);
int				frall(t_data *d);

int				init_txtur(t_data *d);
void			init_game(t_data *d, t_conf *conf);

void			init_plr(t_data *d);

void			init_sprdist(t_data *d);
int				init_sprites(t_data *d);

int				set_txtur(int ***txturs, t_data *d, char **p);
void			set_spr(t_data *d, char *path);
void			set_arr(int ***p, int w, int h);

#endif
