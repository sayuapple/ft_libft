# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 17:52:14 by tkitago           #+#    #+#              #
#    Updated: 2025/01/10 17:52:16 by tkitago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CFLAGS = -Wall -Wextra -Werror
LISTDIR = list_func_utils
PSCMDDIR = push_swap_cmd
PSSORTDIR = push_swap_sort
SRCS		=	main.c \
					ps_atoi.c \
					ps_utils.c \
					$(LISTDIR)/ps_lstnew.c \
					$(PSCMDDIR)/swap.c \
					$(PSCMDDIR)/push.c \
					$(PSCMDDIR)/rotate.c \
					$(PSCMDDIR)/reverse_rotate.c \
					$(PSSORTDIR)/sort_two.c \
					$(PSSORTDIR)/sort_three.c \
					$(PSSORTDIR)/sort_four.c \
					$(PSSORTDIR)/sort_five.c \
					$(PSSORTDIR)/sort_any.c \
					coordinate_compression/coordinate_compression.c
OBJS		=	${SRCS:%.c=%.o}
LIBFTDIR =	./libft


all: ${NAME}

${NAME}: ${OBJS} push_swap.h
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)/libft.a -o $(NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -f ${OBJS}

fclean:clean
	make fclean -C $(LIBFTDIR)
	rm -f ${NAME}

re: fclean $(NAME)

.PHONY: all clean fclean re
