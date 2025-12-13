# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 10:01:12 by ingrid            #+#    #+#              #
#    Updated: 2025/12/13 16:19:43 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

MLX_DIR = lib/mlx_linux
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux
MLX_FLAGS = -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR)

SRCS = $(SRC_DIR)/so_long.c $(SRC_DIR)/utils.c\
		$(SRC_DIR)/map_validate.c $(SRC_DIR)/map_utils.c \
		$(SRC_DIR)/map_read.c $(SRC_DIR)/map_dfs.c \
		$(SRC_DIR)/game_init.c $(SRC_DIR)/game_render.c \
		$(SRC_DIR)/game_events.c $(SRC_DIR)/game_move_player.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "📁 Created obj directory"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $< → $@"

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $@
	@echo "✅ Created $(NAME)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Removed object files and obj directory"

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ Removed executables"

re: fclean all

.PHONY: all clean fclean re
