# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 14:57:04 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 18:04:05 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= replace

SRCS	= main.cpp

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
		@rm *.replace
		@echo [FCLEAN]

re:		fclean all

.PHONY: all fclean re clean
