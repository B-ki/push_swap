NAME =	push_swap
SRCS_P =		srcs/check_param.c		\
			srcs/find_best_move.c		\
			srcs/lis.c					\
			srcs/list.c					\
			srcs/lis_2.c				\
			srcs/median.c				\
			srcs/reverse_rotations.c	\
			srcs/operations.c			\
			srcs/pushswap.c				\
			srcs/push_b_to_a.c			\
			srcs/push_b_to_a_2.c		\
			srcs/push_list.c			\
			srcs/rotations.c			\
			srcs/short_sorting.c		\
			srcs/sort_lis.c				\
			srcs/utils.c				\
			srcs/utils_cost.c

OBJS = $(SRCS_P:.c=.o)
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = gcc
RM = rm -rf
CFLAGS = -Wextra -Wall -Werror
INCLUDES_DIR = ./includes/
INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_DIR)

all: $(NAME) 

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(LIBFT):
			$(MAKE) bonus -C ./libft


$(NAME): $(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_P) $(LIBFT) -o $(NAME)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)


fclean: clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
