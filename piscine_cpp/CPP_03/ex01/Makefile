# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 15:14:19 by agachet           #+#    #+#              #
#    Updated: 2021/10/29 17:42:13 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ScavTrap

CC		=	clang++

FLAGS	=	-Wall -Werror -Wextra

SRCS	=	main.cpp ClapTrap.cpp ScavTrap.cpp

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

.PHONY:		re all fclean clean
