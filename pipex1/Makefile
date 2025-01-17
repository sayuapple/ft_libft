# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 18:27:08 by tkitago           #+#    #+#              #
#    Updated: 2025/01/16 13:00:30 by tkitago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= pipex

DIR				= .
FT				= $(DIR)/libft
INCS_DIR		= $(DIR)/incs
OBJS_DIR		= $(DIR)/objs

MAIN			= $(DIR)/main.c

SRCS			= \
	$(addprefix $(DIR)/srcs/, \
		utils.c \
		cmdline_split.c \
		here_doc.c \
		eval.c \
		pipex.c \
	) \

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			+= -L$(FT)
IDFLAGS			+= -I$(FT)
LIBS			+= -lft
IDFLAGS			+= -I$(INCS_DIR)

.PHONY: all clean fclean re bonus

all: $(FT) $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

bonus: all

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(FT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: test
test: test.c $(OBJS)
	$(CC) -g -fsanitize=address $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

.PHONY: norm
norm: $(MAIN) $(SRCS) $(INCS_DIR)
	@make -C $(FT) norm
	@norminette $^

.PHONY: $(FT)
$(FT):
	@git submodule update --init $@
	@$(MAKE) -C $@
