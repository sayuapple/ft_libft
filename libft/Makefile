# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 13:07:01 by tkitago           #+#    #+#              #
#    Updated: 2025/01/16 13:46:06 by tkitago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c ft_atof.c\
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_2darraynew.c\
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c ft_isspace.c\
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  ft_isalnum.c ft_2darraydel.c\
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  ft_strcmp.c\
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c\
					ft_bufferiodel.c ft_bufferionew.c ft_bufferioread.c ft_joinpath.c ft_readline.c\
					ft_strgencomp.c ft_strgendel.c ft_strgenfetch.c ft_strgenflush.c ft_strgennew.c\
					ft_strgenstr.c ft_strjoin2.c ft_xlst2array.c ft_xlstlen.c ft_xlstappend.c ft_xlstclear.c\
					ft_xlstpop.c ft_ndarraydel.c ft_strgenchr.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
					
OBJS			= $(SRCS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)


clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
