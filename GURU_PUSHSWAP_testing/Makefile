NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/main.c\
		src/index.c\
		src/push.c\
		src/swap.c\
		src/reverse_rotate.c\
		src/rotate.c\
		src/quick_sort.c\
		src/sort_handler.c\
		src/sort_utils.c\
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
