# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 12:53:25 by rbliss            #+#    #+#              #
#    Updated: 2021/04/11 09:53:01 by rbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
INCLUDES = ./include

SRCS = 	cub3d.c \
		utils/ft_atoi.c \
		utils/ft_isdigit.c \
		utils/ft_strchr.c \
		utils/ft_strdup.c \
		utils/ft_strncmp.c \
		utils/ft_trnopr.c \
		config/ft_parser.c \
		config/check.c \
		config/chkmap.c \
		config/parse.c \
		config/utils.c \
		config/init.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		engin/draw/draw_3d.c \
		engin/draw/draw_fc.c \
		engin/draw/draw_spr.c \
		engin/draw/draw_txturs.c \
		engin/draw/draw_txturs2.c \
		engin/draw/utils.c \
		engin/draw/draw_bmp.c \
		engin/event/event.c \
		engin/event/event_move.c \
		engin/event/event_rotate.c \
		engin/utils/init_sprites.c \
		engin/utils/init_plr.c \
		engin/utils/seter.c \
		engin/utils/free.c \
		engin/utils/init_cub.c \
		config/msg_error.c \

OBJSRCS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wextra -Wall -Iinclude
MLX = -framework OpenGL -framework AppKit minilib/libmlx.a

all : $(NAME)

$(NAME) : $(OBJSRCS) ./include/cub3d.h ./include/config.h ./include/engin.h
	$(MAKE) -C minilib 2> /dev/null
	gcc $(CFLAGS) $(OBJSRCS) $(MLX) -o $(NAME)
	@echo "\033[33m[Done !]"

bonus : $(NAME)

clean :
	rm -rf $(OBJSRCS)
fclean : clean
	rm -rf $(NAME)
	make clean -C minilib
	rm -rf screenshot.bmp

re : fclean all

.PHONY: all clean fclean re