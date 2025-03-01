NAME  = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SRCS = srcs/main.c \
       srcs/operations/push.c \
       srcs/operations/swap.c \
       srcs/operations/rotate.c \
       srcs/operations/reverse_rotate.c \
       srcs/parsing/parsing.c \
       srcs/parsing/parsing_utils.c \
       srcs/sorting/sort_utils.c \
       srcs/sorting/small_sort.c \
       srcs/sorting/medium_sort.c \
       srcs/utils/stack_utils.c \
       srcs/utils/error_utils.c \
       libft/ft_atol.c \
       libft/ft_isdigit.c\
       libft/ft_lstadd_back.c \
       libft/ft_lstnew.c \
       libft/ft_lstlast.c \
       libft/ft_split.c
objcts = $(SRCS:.c=.o)

INCLUDES = -I includes



$(NAME): $(objcts) includes/push_swap.h
	$(CC) $(CFLAGS) $(objcts) -o $(NAME)
all: $(NAME)


%.o:%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(objcts)
fclean: clean 
	rm -f $(NAME)



re : fclean all

.PHONY: clean  
