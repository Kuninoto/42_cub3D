OS = $(shell uname)
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g #-Ofast

ifeq ($(OS), Linux)
	CFLAGS += -D OS_LINUX
	MLX_FLAGS = -L ./mlx_linux -lmlx -Ilmlx_linux -lXext -lX11 -lbsd
else
	CFLAGS += -D OS_MACOS
	MLX_FLAGS = -L ./mlx_macos -lmlx -framework OpenGL -framework AppKit
endif

LIBFT = ./libft/libft.a
LINK = -I./includes
VPATH = srcs srcs/parser
RM = rm -rf
NAME = cub3D

TEST_FILE = scenes/alter.cub

PARSER = parse_textures parse_map parse_scene save_player_info
GENERAL = valid_args draw_minimap move_player event_handlers destroy panic put_error\
		  main

SRCS = $(addsuffix .c, $(PARSER))\
	   $(addsuffix .c, $(GENERAL))

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(info Compiling Cub3D for $(OS))
ifeq ($(OS), Linux)
	$(MAKE) -C ./mlx_linux
else
	$(MAKE) -C ./mlx_macos
endif
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LINK)

clean:
	$(RM) $(OBJ_DIR) $(OBJS) 
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all
	$(MAKE) re -C ./libft

run: fclean all
	echo ""
	./$(NAME) $(TEST_FILE)

noleaks: fclean all
	echo ""
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST_FILE)

.SILENT:

.PHONY: all cub3D clean fclean re obj
