# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 17:46:31 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 18:11:32 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= KarenFilter

CC		= clang++

FLAGS	= -Werror -Wall -Wextra

SRCS	= main.cpp Karen.cpp

OBJS	= $(SRCS:.cpp=.o)

%.o:	%.cpp
		$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

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
