NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c init_stack.c assign_ranks.c radix_sort.c \
       push_command.c rotation_command.c small_sort.c swap_command.c\
		reverse_rotation_command.c ft_split.c ft_atoi.c error_utils.c\
		is_num.c contains_value.c small_sort_utils.c quick_sort.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
