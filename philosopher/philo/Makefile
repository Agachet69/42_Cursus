# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 18:42:34 by agachet           #+#    #+#              #
#    Updated: 2021/11/03 18:50:52 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

PATH		=	srcs

SRCS_NAME	=	main.c ft_init.c ft_do.c

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
