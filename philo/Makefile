# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 13:57:52 by tkitago           #+#    #+#              #
#    Updated: 2025/03/11 13:57:56 by tkitago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

DIR = .
INC_DIR = $(DIR)/include
OBJS_DIR = $(DIR)/objs
SRCS_DIR = $(DIR)/srcs
MAIN = $(DIR)/main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I $(INC_DIR) -g3
LDFLAGS = -lpthread

SRCS = \
	$(MAIN) \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/monitor.c \
	$(SRCS_DIR)/philo.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS_DIR)/%.o: $(DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 