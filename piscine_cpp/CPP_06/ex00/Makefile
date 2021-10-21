# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 17:48:48 by agachet           #+#    #+#              #
#    Updated: 2021/10/15 17:52:22 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	convert

CC		=	clang++

FLAGS	=	Werror Wextra Wall

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o:	%.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo [$(NAME)]

clean:
		@rm -f $(OBJS)
		@echo [CLEAN]

fclean:
		@rm -f $(OBJS) $(NAME)
		@echo [FCLEAN]

re:		fclean all


.PHONY: re all fclean clean
