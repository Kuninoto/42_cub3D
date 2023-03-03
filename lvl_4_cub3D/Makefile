CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g # -Ofast
MLX_FLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
LINK = -I./includes
VPATH = srcs srcs/parser
RM = rm -rf
NAME = cub3D

TEST_FILE = scenes/alter.cub

PARSER = parse_scene parse_textures
GENERAL = valid_args destroy panic put_error\
		  main

SRCS = $(addsuffix .c, $(PARSER))\
	   $(addsuffix .c, $(GENERAL))

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LINK)

clean:
	$(RM) $(OBJ_DIR) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	echo ""
	./$(NAME) $(TEST_FILE)

noleaks: re
	echo ""
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(TEST_FILE)

.SILENT:

.PHONY: all cub3D clean fclean re
