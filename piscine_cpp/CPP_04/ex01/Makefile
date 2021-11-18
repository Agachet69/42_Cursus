# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 16:55:40 by agachet           #+#    #+#              #
#    Updated: 2021/10/27 17:42:11 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Polymorphism-01

CC		=	clang++

FLAGS	=	-Werror -Wextra -Wall

SRCS	=	main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o:		%.cpp
			@$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo [$(NAME)]

clean:
			@rm -f $(OBJS)
			@echo [CLEAN]

fclean:
			@rm -f $(OBJS) $(NAME)
			@echo [FCLEAN]

re:			fclean all

.PHONY:		all re clean fclean

