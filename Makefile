# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 15:08:38 by jgyles            #+#    #+#              #
#    Updated: 2021/11/16 14:38:25 by jgyles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= fdf

SRC_DIR				= ./srcs/
SRC_LIST			= main.c get_next_line.c\
					get_next_line_utils.c read_file.c\
					draw.c utils.c
SRC					= $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR				= objs/
OBJ_LIST			= $(patsubst %.c, %.o, $(SRC_LIST))
OBJ					= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

MINILIBX_DIR		= ./mlx/
MINILIBX 			= $(MINILIBX_DIR)libmlx.a
MINILIBX_HEADERS	= $(MINILIBX_DIR)


LIBFT_DIR			= ./Libft/
LIBFT				= $(LIBFT_DIR)libft.a
LIBFT_HEADERS		= $(LIBFT_DIR)

CC					= gcc
FLAGS				= -Wall -Wextra -Werror -O3
LIBRARIES			= -lmlx -lm -lft\
		-L$(LIBFT_DIR) -L$(MINILIBX_DIR)\
		-framework OpenGL -framework AppKit

HEADER_DIR			= ./includes/
HEADERS_LIST		= fdf.h get_next_line.h
HEADERS				= $(addprefix $(HEADER_DIR), $(HEADERS_LIST))

INCLUDES			= -I$(HEADER_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ) 
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(MINILIBX) :
	make -C $(MINILIBX_DIR)

clean :
	make -C $(MINILIBX_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(MINILIBX)
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all