NAME = cub3D

FLAGS = -Wall -Wextra -Werror

MLX_PATH = mlx/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS = -lXext -lX11 -lm

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

FILES = 	main.c \
			termination.c \
			exec/exec.c \
			exec/handle_keys.c \
			exec/handle_moves.c \
			exec/make_move.c \
			exec/raycasting.c \
			exec/rotate_player.c \
			exec/set_first_player_direction.c \
			exec/fill_frame.c \
			init/init_images.c \
			init/init_mlx.c \
			init/init_ray.c \
			init/init_state.c \
			init/init_textures.c \
			parsing/are_textures_ok.c \
			parsing/fetch_raw_file.c \
			parsing/fetch_scene_descr_content.c \
			parsing/is_file_ok.c \
			parsing/is_map_ok.c \
			parsing/is_map_surrounded_by_walls.c \
			parsing/make_map.c \
			parsing/parsing_helpers.c \
			parsing/parsing.c \
			parsing/set_colors.c

OBJS =		main.o \
			termination.o \
			exec.o \
			handle_keys.o \
			handle_moves.o \
			make_move.o \
			raycasting.o \
			rotate_player.o \
			set_first_player_direction.o \
			fill_frame.o \
			init_images.o \
			init_mlx.o \
			init_ray.o \
			init_state.o \
			init_textures.o \
			are_textures_ok.o \
			fetch_raw_file.o \
			fetch_scene_descr_content.o \
			is_file_ok.o \
			is_map_ok.o \
			is_map_surrounded_by_walls.o \
			make_map.o \
			parsing_helpers.o \
			parsing.o \
			set_colors.o

INC = -I ./includes/ -I ./$(LIBFT_PATH) -I ./$(MLX_PATH)

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	make -sC $(MLX_PATH)

$(LIBFT):
	make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) $(INC) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJS): $(FILES)
	cc -c $(FLAGS) $(FILES) $(INC)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
