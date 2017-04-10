# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 12:46:14 by ashulha           #+#    #+#              #
#    Updated: 2017/03/09 12:46:15 by ashulha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LNAM = libft.a

LIBF = ./libft

INCL = libftprintf.h

SRCS = *.c

CCFL = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@$(CCFL) -c $(SRCS)
	@ar rc $(NAME) *.o

clean:
	@make -C $(LIBF) clean
	@rm -rf *.o

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

