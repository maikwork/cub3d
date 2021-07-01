/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:11:45 by rbliss            #+#    #+#             */
/*   Updated: 2021/04/09 13:21:26 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGIN_H
# define ENGIN_H

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_tmpimg
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_tmpimg;

typedef struct s_plr
{
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		rtspd;
	float		mvspd;
}				t_plr;

typedef struct s_play
{
	double		camera_x;
	double		ray_dir_y;
	double		ray_dir_x;
	int			map_x;
	int			map_y;
	int			mdouble;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			color;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_play;

typedef struct s_plspr
{
	float		sprite_x;
	float		sprite_y;
	float		inv_det;
	float		transf_x;
	float		transf_y;
	int			spr_scr_x;
	int			spr_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			de;
	int			tex_y;
	int			color;
}				t_plspr;

typedef struct s_plfc
{
	float		ray_dir_x0;
	float		ray_dir_y0;
	float		ray_dir_x1;
	float		ray_dir_y1;
	int			p;
	float		pos_z;
	float		row_dist;
	float		floor_step_x;
	float		floor_step_y;
	float		floor_x;
	float		floor_y;
	int			cell_x;
	int			cell_y;
	int			tx;
	int			ty;
	int			floor_text;
	int			ceil_text;
	int			color;
}				t_plfc;

typedef struct s_bmp_file_header
{
	char		*type;
	int			size;
	int			reserved;
	int			offset;
}				t_bmp_file_header;

typedef struct s_bmp_info_header
{
	int			size;
	int			width;
	int			height;
	int			planes;
	int			bpp;
	int			compression;
	int			image_size;
	int			x_pixel;
	int			y_pixel;
	int			total_color;
	int			important_color;
}				t_bmp_info_header;

typedef struct s_bmp
{
	t_bmp_file_header	file;
	t_bmp_info_header	info;
}				t_bmp;

typedef struct s_sprarr
{
	float		x;
	float		y;
}				t_sprarr;

#endif
