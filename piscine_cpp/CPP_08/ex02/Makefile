# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:11:06 by agachet           #+#    #+#              #
#    Updated: 2021/10/21 18:50:33 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	FIND

CC		=	clang++

FLAGS	=	Werror Wextra Wall

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o:	%.cpp
		@$(CC) $(FLAGS)-c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo [$(NAME)]

clean:
			@rm -f $(OBJS)
			@echo [CLEAN]

fclean:
			@rm -f $(OBJS) $(NAME)
			@echo [FCLEAN]

re:			fclean all

.PHONY:		all re clean fclean
