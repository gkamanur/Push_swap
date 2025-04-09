# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 13:30:40 by gkamanur          #+#    #+#              #
#    Updated: 2025/04/09 15:46:06 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

CC = cc -fsanitize=address -g

FLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRC = src/main/main.c\
	  src/main/ft_split.c\
	  src/main/input_validation.c\
	  src/main/list_utils.c\
	  src/main/pick_node.c\
	  src/main/str_utils.c\
	  src/stack_opers/swap.c\
	  src/stack_opers/push.c\
	  src/stack_opers/rotate.c\
	  src/stack_opers/reverse_rotate.c\
	  src/sort_opers/sort_utils.c
OBJS = $(SRC:.c=.o)

HDR = include/pushswap.h\
	  include/colors.h
	  
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	
%.o: %.c $(HDR)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)
	
fclean : clean
		$(RM) $(NAME)
		
re : fclean all