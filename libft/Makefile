# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeorgie <tgeorgie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 08:19:01 by tgeorgie          #+#    #+#              #
#    Updated: 2023/11/10 10:58:24 by tgeorgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	./
HEADER	=	./
AR		=	ar -cr

CFILES	=	$(SRC)ft_isalpha.c $(SRC)ft_isdigit.c $(SRC)ft_isalnum.c \
			$(SRC)ft_isascii.c $(SRC)ft_isprint.c $(SRC)ft_strlen.c \
			$(SRC)ft_memset.c $(SRC)ft_bzero.c $(SRC)ft_memcpy.c \
			$(SRC)ft_memmove.c $(SRC)ft_strlcpy.c $(SRC)ft_strlcat.c \
			$(SRC)ft_toupper.c $(SRC)ft_tolower.c $(SRC)ft_strchr.c \
			$(SRC)ft_strrchr.c $(SRC)ft_strncmp.c $(SRC)ft_memchr.c \
			$(SRC)ft_memcmp.c $(SRC)ft_strnstr.c $(SRC)ft_atoi.c \
			$(SRC)ft_calloc.c $(SRC)ft_strdup.c \
  			$(SRC)ft_substr.c $(SRC)ft_strjoin.c $(SRC)ft_strtrim.c \
			$(SRC)ft_split.c $(SRC)ft_itoa.c $(SRC)ft_strmapi.c \
			$(SRC)ft_striteri.c $(SRC)ft_putchar_fd.c $(SRC)ft_putstr_fd.c \
			$(SRC)ft_putendl_fd.c $(SRC)ft_putnbr_fd.c
OFILES	=	$(CFILES:.c=.o)

CBONUS	=	$(SRC)ft_lstnew_bonus.c $(SRC)ft_lstadd_front_bonus.c \
			$(SRC)ft_lstsize_bonus.c $(SRC)ft_lstlast_bonus.c \
			$(SRC)ft_lstadd_back_bonus.c $(SRC)ft_lstdelone_bonus.c \
			$(SRC)ft_lstclear_bonus.c $(SRC)ft_lstiter_bonus.c \
			$(SRC)ft_lstmap_bonus.c
OBONUS	=	$(CBONUS:.c=.o)

.o: .c
	$(CC) $(CFLAGS) -c -I $(HEADER) $? 

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)
	ranlib $(NAME)

all: $(NAME)

bonus: .bonus 

.bonus: $(OFILES) $(OBONUS)
	$(AR) $(NAME) $^ 
	ranlib $(NAME)
	@touch .bonus

clean:
	rm -f $(OFILES) $(OBONUS)
	@rm -f .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus
