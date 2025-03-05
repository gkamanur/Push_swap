NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	main.c\
		index.c\
		push.c\
		swap.c\
		reverse_rotate.c\
		rotate.c\
		quick_sort.c\
		sort_handler.c\
		sort_utils.c\
		free_stack.c\
		parse.c\
		error_free.c\
		libft/*.c

$(NAME) :
	make -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	make clean -C libft

re : fclean all
