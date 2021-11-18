# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 16:55:27 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 18:47:08 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Fixed

CC		=	clang++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp Fixed.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o:	%.cpp
		@$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo [$(NAME)]

clean:
		@rm -f $(OBJS)
		@echo [CLEAN]

fclean:
		@rm -f $(OBJS) $(NAME)
		@echo [FCLEAN]

re:		fclean all

.PHONY: re all fclean clean
