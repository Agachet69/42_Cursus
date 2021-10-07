# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 14:57:04 by agachet           #+#    #+#              #
#    Updated: 2021/09/21 16:58:39 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= replace

SRCS	= main.cpp

CC		= clang++

OBJS	= ${SRCS:.cpp=.o}

FLAGS	= Wall Wextra Werror

%.o:	%.cpp
		${CC} ${CFLAGS} -c $< -o $@

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

.PHONY: all fclean re clean
