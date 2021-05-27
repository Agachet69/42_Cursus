# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 18:42:34 by agachet           #+#    #+#              #
#    Updated: 2021/05/26 18:57:04 by agachet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	philo-one

PATH		=	srcs

SRCS_NAME	=	main.c

OBJS		=	$(SRCS:.c=.o)

FLAGS		=	-Wall -Werror -Wextra

SRCS		= $(addprefix $(PATH)/,$(SRCS_NAME))

%.o:		%.c ./include/philosopher.h
			gcc $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:
			rm -f $(OBJS) $(NAME)

re:			fclean all

norme:
			@norminette $(SRCS) include/philosopher.h

.PHONY:		all fclean clean re norme
