# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 19:00:32 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 17:45:29 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Reference

CC		= clang++

SRCS	= main.cpp

OBJS	= ${SRCS:.cpp=.o}

FLAGS	= -Werror -Wextra -Wall

%.o	:	%.cpp
		$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		@rm -f $(OBJS)
		@echo [CLEAN]

fclean:
		@rm -rf ${NAME} ${OBJS}
		@echo [FCLEAN]

re:		fclean all

.PHONY: all fclean re

