/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:24:13 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:17:37 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "../utils/libft.h"
# include "fcntl.h"

typedef struct s_chrconf
{
	int			r;
	int			so;
	int			no;
	int			we;
	int			ea;
	int			spr;
	int			f;
	int			c;
}				t_chrconf;

typedef struct s_winsz
{
	int			win_h;
	int			win_w;
}				t_winsz;

typedef struct s_txturs
{
	char		*t_no;
	char		*t_so;
	char		*t_we;
	char		*t_ea;
	char		*t_spr;
}				t_txturs;

typedef struct s_clrs
{
	int			clr_c;
	int			clr_f;
}				t_clrs;

typedef struct s_mapsz
{
	int			h;
	int			w;
}				t_mapsz;

typedef struct s_map
{
	char		**arr;
	int			h;
	int			cnt_h;
}				t_map;

typedef struct s_conf
{
	t_winsz		*winsz;
	t_txturs	*txturs;
	t_clrs		*clrs;
	t_map		*map;
	int			err;
}				t_conf;

typedef struct s_chkmap
{
	int			i;
	int			j;
	int			dir;
	int			s_x;
	int			s_y;
}				t_chkmap;

typedef struct s_itdar
{
	int			i;
	int			j;
}				t_itdar;

void			set_map(int fd, t_map *map);
int				ft_parser(char *path, t_conf *conf);
void			init_chrconf(t_chrconf *chrconf);
int				init_conf(t_conf *conf, char *path);
int				prsdsp(t_conf *conf, char *s);
int				prsmap(t_conf *conf, char *s);
int				prstxturs(t_conf *conf, char *s);
int				prsclr(t_conf *conf, char *s);
int				is_validchr(char s);
int				skip_digit(char *s);
int				skip_space(char *s);
int				check_chrcnf(t_chrconf *chrconf, char *line);
int				check_map(t_conf *conf);
int				check_flcnf(t_chrconf *chrcnf);
int				chkpath(t_conf *conf, char *s);
int				chknbr(t_conf *conf, char *s, int cnt);
int				chkarnd(char **map, int max, int h, t_itdar it);
int				chkmap(char **map, int h, int max);
int				chkmap1(t_conf *conf);
int				srch_h(char *path);
int				msgerr(int err);
int				chkbrd(char *s);
int				chkln(char *s);
int				setclr(char *s, int *p_i, int *p_j, int *nbr);
void			flmap(t_conf *conf, char **map, int max);

#endif
