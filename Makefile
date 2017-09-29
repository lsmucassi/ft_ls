# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 14:57:22 by lmucassi          #+#    #+#              #
#    Updated: 2017/09/29 13:52:53 by lmucassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

CFLAGS	= -Wall -Werror -Wextra -I

FILES	= main.c	direct.c	errors.c	free.c

LIBFT	= ./libft

SRC		= $(addprefix, $(FILES))

OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo "making libft"  make -C $(LIBFT)
	@echo "compiling ..." gcc $(CFLAGS) -o $@ $^ -L$(LIBFT) -lft

%.o:		%.c
	@echo "compiling with C flags"
	gcc $(CFLAGS) -o $@ -c $<

clean:
	@echo "cleaning project"
	rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean:		clean
	@echo "cleaning project"
	rm -f $(NMAE)
	@make -C $(LIBFT) fclean

re: fclean all
