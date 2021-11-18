# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 19:59:42 by agachet           #+#    #+#              #
#    Updated: 2021/11/04 19:59:05 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Form

CC		=	clang++

FLAGS	=	-Werror -Wextra -Wall

SRCS	=	main.cpp Bureaucrat.cpp Form.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o:	%.cpp
		@$(CC) $(FLAGS) -c $< -o $@

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

re:		fclean all


.PHONY: re all fclean clean
