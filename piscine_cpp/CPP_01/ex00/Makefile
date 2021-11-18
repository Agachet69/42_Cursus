# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 15:04:20 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 17:35:29 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= Horde

CC		= clang++

SRCS 	= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror

%.o:	%.cpp
		$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:
		rm -rf ${NAME} $(OBJS)

re:		fclean all

.PHONY: all fclean re

