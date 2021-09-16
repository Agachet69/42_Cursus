# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 17:27:52 by agachet           #+#    #+#              #
#    Updated: 2021/09/16 19:44:33 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= Annuaire

CC		= clang++

SRCS 	= main.cpp Repertoire_class.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror

%.o:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean:
	rm -rf ${NAME} ${OBJS}

re: fclean all

.PHONY: all fclean re
