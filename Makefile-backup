# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 10:15:14 by tgeorgie          #+#    #+#              #
#    Updated: 2023/11/16 15:01:00 by tgeorgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LIB_SRC		=	./libft/
HEADER		=	./libft/
PRINT_SRC	=	./
AR			=	ar -cr

LIB_FN		=	isalpha isdigit isalnum isascii isprint strlen \
				memset bzero memcpy memmove strlcpy strlcat \
				toupper tolower strchr strrchr strncmp memchr \
				memcmp strnstr atoi calloc strdup \
				substr strjoin strtrim split itoa strmapi \
				striteri putchar_fd putstr_fd putendl_fd putnbr_fd \
				lstnew_bonus lstadd_front_bonus \
				lstsize_bonus lstlast_bonus \
				lstadd_back_bonus lstdelone_bonus \
				lstclear_bonus lstiter_bonus \
				lstmap_bonus
LIB_C		=	$(addprefix $(LIB_SRC)ft_, $(addsuffix .c, $(LIB_FN)))
LIB_O		=	$(LIB_C:.c=.o)

PRINT_FN	=	printf print_unsigned print_int_str print_hex
PRINT_C		=	$(addprefix $(PRINT_SRC)ft_, $(addsuffix .c, $(PRINT_FN)))
PRINT_O		=	$(PRINT_C:.c=.o)

.o: .c
	$(CC) $(CFLAGS) -c -I $(HEADER) $? 

$(NAME): $(LIB_O) $(PRINT_O)
	$(AR) $(NAME) $?
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(LIB_O) $(PRINT_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus
