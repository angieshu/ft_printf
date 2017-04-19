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

NAME =				libftprintf.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

FT_SRC_DIR =		./libft
PRINTF_SRC_DIR =	./src

HEADER =			$(FT_SRC_DIR)libft.h
PRINTF_SRC_HEADER =	$(PRINTF_SRC_DIR)libftprintf.h

FT_COMPILED =		ft_atoi.o ft_bzero.o ft_countnumber.o ft_countword.o ft_hcf.o ft_isalnum.o \
					ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_itoa_base.o \
					ft_itoa_double.o ft_itoa_double_g.o ft_itoa_exp.o ft_itoa_negative.o \
					ft_itoa_negative_decimal.o ft_lcn.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o \
					ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o \
					ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_power.o \
					ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
					ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o \
					ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o \
					ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o \
					ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o \
					ft_strrchr.o ft_strrev.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o \
					ft_tolower.o ft_toupper.o ft_toupper_s.o ft_itoa_signed.o ft_itoa_unsigned.o

PRINTF_COMPILED =	check_format.o ft_printf.o identification_1.o identification_2.o identification_3.o \
 					count_position.o flags_hash.o flags_set.o flags_others.o ft_build.o length_precision.o \
 					read_wchar.o min_width.o

COMPILED =			$(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

$(NAME): $(FT_COMPILED) $(PRINTF_COMPILED) $(COMPILED)
	@ar rcs $(NAME) $(COMPILED)
	@echo "made" $(NAME)


clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
