# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 16:00:35 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 18:08:13 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Karen

CC		= clang++

FLAGS	= -Werror -Wextra -Wall

SRCS	= Karen.cpp main.cpp

OBJS	= $(SRCS:.cpp=.o)

%.o:	%.cpp
		$(CC) $(FLAGS) -c $< -o $@

all:	${NAME}

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			@rm-f $(OBJS)
			@echo [CLEAN]

fclean:
			@rm -f $(OBJS) $(NAME)
			@echo [FCLEAN]

re:			fclean all

.PHONY:		clean all fclean re
