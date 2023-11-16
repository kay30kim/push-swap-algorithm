# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 21:13:41 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/15 15:54:44 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	push_swap

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources
#SERVER_OBJS	=	$(SERVER_SRCS:.c=.o) ㅎㅐ야할거

#Library
LIBFT		=	./library/libft
LIBPF		=	./library/ft_printf
LIBS		=	$(LIBFT)/libft.a $(LIBPF)/libftprintf.a
HEADERS		=	-I$(LIBFT)/include -I$(LIBPF) -Iinclude

###
all : libft libpf $(NAME)

libft :
	$(MAKE) -C $(LIBFT)

libpf :
	$(MAKE) -C $(LIBPF)

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

$(NAME) :	

clean :
# rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) 해해야할거
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBPF) clean

fclean : clean
#	rm -rf $(SERVER) $(CLIENT) 해해야할거
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBPF) fclean

re : fclean all

.PHONY : all libft libpf clean fclean re