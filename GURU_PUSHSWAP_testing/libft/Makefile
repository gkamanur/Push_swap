# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 12:22:11 by gkamanur          #+#    #+#              #
#    Updated: 2025/02/24 15:48:23 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and corresponding object files
SRC = 	ft_isalpha.c   \
		ft_isdigit.c   \
		ft_isalnum.c   \
		ft_isascii.c   \
		ft_isprint.c   \
		ft_strlen.c    \
		ft_memset.c    \
		ft_bzero.c     \
		ft_memcpy.c    \
		ft_memmove.c   \
		ft_strlcpy.c   \
		ft_strlcat.c   \
		ft_toupper.c   \
		ft_tolower.c   \
		ft_strchr.c    \
		ft_strrchr.c   \
		ft_strncmp.c   \
		ft_strnstr.c   \
		ft_atoi.c      \
		ft_calloc.c    \
		ft_strdup.c    \
		ft_memcmp.c    \
		ft_memchr.c    \
		ft_substr.c    \
		ft_strjoin.c   \
		ft_strtrim.c   \
		ft_split.c     \
		ft_itoa.c      \
		ft_strmapi.c   \
		ft_striteri.c  \
		ft_putchar_fd.c  \
		ft_putstr_fd.c   \
		ft_putendl_fd.c  \
		ft_putnbr_fd.c   \
		ft_lstnew.c      \
		ft_lstsize.c     \
		ft_lstlast.c     \
		ft_lstadd_back.c  
		
OBJ = $(SRC:.c=.o)

# Default rule to create the library
all: $(NAME)

# Rule to create the library from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."

# Rule to compile each .c file to .o file
%.o:%.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	rm -f $(OBJ)
	@echo "Object files removed."

# Rule to clean object files and the library
fclean: clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed."

# Rule to recompile everything
re: fclean all

# Rule to run the code 
# run:
# 	$(CC) -I $(INCDIR) *.c -L. -lft -o a.out && ./a.out