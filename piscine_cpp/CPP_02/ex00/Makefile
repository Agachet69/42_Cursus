# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:33:05 by agachet           #+#    #+#              #
#    Updated: 2021/09/23 15:44:57 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Fixed

CC		= clang++

FLAGS	= Werror Wextra Wall

SRCS	= main.cpp Fixed.cpp

OBJS	= $(SRCS:.cpp=.o)

%.o:	%.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo [$(NAME)]

clean:
			@rm -f $(OBJS)
			@echo [CLEAN]

fclean:
			@rm -f $(OBJS) $(NAME)
			@echo [FCLEAN]

re:			fclean all

.PHONY:		clean all fclean re

