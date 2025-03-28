CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes 
VPATH = conversions debug_utils ft_printf memory string
RM = rm -rf
NAME = libft.a

CONVERSIONS = fits_in_longlong ft_atof ft_atoi ft_atol\
			  ft_atoll ft_itoa ft_lltoa ft_ltoa\
			  ft_utoa represents_float

DEBUG_UTILS = print_char_matrix print_int_array

FT_PRINTF = prt_hexa prt_int prt_ptr prt_str prt_unsigned\
			ft_printf

MEMORY = free_matrix ft_bzero ft_calloc ft_memchr\
		 ft_memcmp ft_memcpy ft_memmove ft_memset\
		 matrix_len

STRING =  ft_split ft_strchr ft_strcpy ft_strdup\
		  ft_strjoin ft_strlcat ft_strlcpy ft_strlen\
		  ft_strncmp ft_strnstr ft_strrchr ft_strtrim\
		  ft_substr is_all_digits is_onstr join_free_both\
		  join_free join_freev2 only_spaces split_per_set\
		  streq trim_free

GENERAL = ft_putnbr_fd get_next_line\

SRCS = $(addsuffix .c, $(CONVERSIONS))\
	   $(addsuffix .c, $(DEBUG_UTILS))\
	   $(addsuffix .c, $(FT_PRINTF))\
	   $(addsuffix .c, $(MEMORY))\
	   $(addsuffix .c, $(STRING))\
	   $(addsuffix .c, $(GENERAL))

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJ_DIR) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
