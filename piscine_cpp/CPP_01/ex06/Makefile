# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 17:46:31 by agachet           #+#    #+#              #
#    Updated: 2021/09/21 17:56:59 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= karenFilter

CC		= clang++

FLAGS	= Werror Wall Wextra

SRCS	= main.cpp Karen.cpp

OBJS	= $(SRCS:.cpp=.o)

%.o:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@rm-f $(OBJS)
			@echo [CLEAN]

fclean:
			@rm -f $(OBJS) $(NAME)
			@echo [FCLEAN]

re:			fclean all

.PHONY:		clean all fclean re
