NAME =	checker
SRCS_P =	check_param.c				\
			gnl.c						\
			list.c						\
			main_checker.c				\
			operations.c				\
			push_list.c					\
			rotations.c					\
			reverse_rotations.c

OBJS = $(SRCS_P:.c=.o)
LIBFT_DIR = ../libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = gcc
RM = rm -rf
CFLAGS = -Wextra -Wall -Werror
INCLUDES_DIR = ../includes/
INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_DIR)

all: $(NAME) 

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
			$(MAKE) bonus -C $(LIBFT_DIR)


$(NAME): $(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_P) $(LIBFT) -o $(NAME)

clean:		
			$(MAKE) clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)


fclean: clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
