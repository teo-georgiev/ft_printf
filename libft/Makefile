# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 08:19:01 by tgeorgie          #+#    #+#              #
#    Updated: 2023/11/10 10:07:01 by tgeorgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LIB_SRC		=	./
HEADER		=	./
AR			=	ar -cr

LIB_FN		=	isalpha isdigit isalnum isascii isprint strlen \
				memset bzero memcpy memmove strlcpy strlcat \
				toupper tolower strchr strrchr strncmp memchr \
				memcmp strnstr atoi calloc strdup \
				substr strjoin strtrim split itoa strmapi \
				striteri putchar_fd putstr_fd putendl_fd putnbr_fd \

LIB_C		=	$(addprefix $(LIB_SRC)ft_, $(addsuffix .c, $(LIB_FN)))
LIB_O		=	$(LIB_C:.c=.o)

BONUS_FN	=	lstnew_bonus lstadd_front_bonus \
				lstsize_bonus lstlast_bonus \
				lstadd_back_bonus lstdelone_bonus \
				lstclear_bonus lstiter_bonus \
				lstmap_bonus
BONUS_C		=	$(addprefix $(LIB_SRC)ft_, $(addsuffix .c, $(BONUS_FN)))
BONUS_O		=	$(BONUS_C:.c=.o)

.o: .c
	$(CC) $(CFLAGS) -c -I $(HEADER) $? 

$(NAME): $(LIB_O)
	$(AR) $(NAME) $^
	ranlib $(NAME)

all: $(NAME)

bonus: .bonus 

.bonus: $(BONUS_O)
	$(AR) $(NAME) $^ 
	ranlib $(NAME)
	@touch .bonus

clean:
	rm -f $(LIB_O) $(BONUS_O)
	@rm -f .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus
