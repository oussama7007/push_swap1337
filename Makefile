NAME  = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SRCS = srsc/main.c \
	   srsc/operations/push.c \
	   srsc/operations/swap.c \
	   srcs/operations/rotate.c \
	   srcs/operations/reverse_rotate.c \
       srcs/parsing/parsing.c \
       srcs/parsing/parsing_utils.c \
       srcs/sorting/sort_utils.c \
       srcs/sorting/small_sort.c \
       srcs/sorting/large_sort.c \
       srcs/utils/stack_utils.c \
       srcs/utils/error_utils.c \
	   libft/ft_atoi.c 

objcts = $(SRCS:.c=.o)

INCLUDES = -I includes
all: $(NAME)

NAME: $(objcts)
	$(CC) $(CFLAGS) $(objcts) -o $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(SRCS)
fclean: clean 
	rm -f $(NAME)

re : fclean all

.PHONY: clean  