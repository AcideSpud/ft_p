# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 21:13:50 by ajulien           #+#    #+#              #
#    Updated: 2015/03/16 18:47:41 by ajulien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = includes/
SRC = ft_putchar.c ft_putstr.c ft_get_next_line.c ft_ptrlen.c\
	   ft_atoi.c ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnew.c \
	   ft_bzero.c ft_memcmp.c ft_putstr.c ft_striteri.c ft_strnstr.c \
	   ft_isalnum.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c \
	   ft_isalpha.c ft_memdel.c ft_strcat.c ft_strlcat.c ft_strsplit.c \
	   ft_isascii.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strstr.c \
	   ft_isdigit.c ft_memset.c ft_strclr.c ft_strmap.c ft_strsub.c \
	   ft_isprint.c ft_putchar.c ft_strcmp.c ft_strmapi.c ft_strtrim.c \
	   ft_putchar_fd.c ft_strcpy.c ft_strncat.c ft_tolower.c ft_strndup.c \
	   ft_itoa.c ft_putendl.c ft_strdel.c ft_strncmp.c ft_toupper.c \
	   ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c \
	   ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_strlen.c \
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	   ft_strfsplit.c
SRCS = $(addprefix src/, $(SRC))
OBJ = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $<  $(CFLAGS) -I $(INCLUDE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

s_fclean:
	rm -rf $(NAME)

re: fclean all
