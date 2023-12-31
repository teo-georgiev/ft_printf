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

PRINT_FN	=	printf print_unsigned print_int_str print_hex
PRINT_C		=	$(addprefix $(PRINT_SRC)ft_, $(addsuffix .c, $(PRINT_FN)))
PRINT_O		=	$(PRINT_C:.c=.o)

.o: .c
	$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

$(NAME): $(PRINT_O)
	@cd libft && make && make clean
	@mv libft/libft.a $(NAME)
	@cd ../
	$(AR) $(NAME) $?
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(PRINT_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus
