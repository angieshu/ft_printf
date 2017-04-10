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

SRCS = ./src

CCFL = -Wall -Wextra -Werror

COMP = $(LIBFT_COMP) $(PRINTF_COMP)

all: $(NAME)

$(NAME): $(COMP)
	@ar rc $(NAME) $(COMP)
	@ranlib $(NAME)

$(LIBFT_COMP): %.o: $(LIBF)/%.c
	@gcc -c $(CCFL) -I $(LIBF) $< -o $@

$(PRINTF_COMP): %.o: $(SRCS)/%.c
	@gcc -c $(CCFL) -I $(LIBF) -I $(SRCS) $< -o $@

clean:
	@bin/rm -rf $(COMP)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

