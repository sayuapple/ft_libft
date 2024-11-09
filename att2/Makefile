# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 10:46:41 by tkitago           #+#    #+#              #
#    Updated: 2024/11/05 14:42:09 by tkitago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_calloc.c ft_char.c ft_format.c ft_hex.c\
		ft_int.c ft_itoa.c ft_pointer_base.c ft_pointer.c\
		ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_str_count.c\
		ft_str.c ft_strdup.c ft_strlen.c ft_tolower.c ft_tolower_all.c\
		ft_uint.c ft_unfo_output.c


OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all