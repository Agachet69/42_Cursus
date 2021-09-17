# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 18:52:17 by agachet           #+#    #+#              #
#    Updated: 2021/09/17 18:09:13 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= megaphone

CC		= clang++

SRCS 	= megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror

%.o:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:
		rm -rf ${NAME} $(OBJS)

re:		fclean all

.PHONY: all fclean re
