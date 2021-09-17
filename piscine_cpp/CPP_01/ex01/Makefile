# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 18:01:59 by agachet           #+#    #+#              #
#    Updated: 2021/09/17 18:08:35 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= Horde

CC		= clang++

SRCS 	= Zombie.cpp ZombieHorde.cpp main.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror

%.o:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		@rm -f $(OBJS)
		@echo [CLEAN]

fclean:
		@rm -rf ${NAME} ${OBJS}
		@echo [FCLEAN]

re:		fclean all

.PHONY: all fclean re
