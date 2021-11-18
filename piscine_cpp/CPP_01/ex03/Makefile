# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:18:16 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 17:51:05 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= violence

SRCS	= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CC		= clang++

OBJS	= ${SRCS:.cpp=.o}

FLAGS	= -Wall -Wextra -Werror

%.o:	%.cpp
		${CC} ${FLAGS} -c $< -o $@

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
