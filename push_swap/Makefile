# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 13:45:06 by agachet           #+#    #+#              #
#    Updated: 2021/05/25 15:55:11 by agachet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

PATH		= 	srcs

SRCS_NAME	=	main.c ft_lst.c ft_operation.c ft_verif_lst.c\
				ft_operation2.c ft_tri.c ft_do_tri.c ft_simple.c ft_norme.c

OBJS		= ${SRCS:.c=.o}

FLAGS		= -Wall -Werror -Wextra

SRCS		= $(addprefix ${PATH}/,${SRCS_NAME})

%.o: %.c ./include/push_swap.h
		gcc $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME) : $(OBJS)
			gcc $(FLAGS) $(OBJS)  -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

norme:
	@norminette $(SRCS) include/push_swap.h

