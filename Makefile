# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 10:15:14 by tgeorgie          #+#    #+#              #
#    Updated: 2023/11/10 10:35:10 by tgeorgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	./

SRC		=	./
HEADER	=	./

FUNCT	=	printf
CFILES	=	$(addprefix $(SRC), $(addsuffix .c, $(FUNCT)))
OFILES	=	$(CFILES:.c=.o)

make_libft:
	@cd libft
	@make
	@make bonus
	@cd ..
	
.o: .c
	$(CC) $(FLAGS) -c -I $(HEADER) $?

$(NAME): make_libft $(OFILES)
	$(AR) $(NAME) $(OFILES)
