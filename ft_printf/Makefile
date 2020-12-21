# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/11 11:11:12 by agachet           #+#    #+#              #
#    Updated: 2020/12/21 14:09:31 by agachet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_affadresse.c ft_base.c ft_do_spaces.c\
			ft_do_zero.c ft_initstruct.c ft_printf_calloc.c ft_printfdo.c\
			ft_do_moins.c ft_do_precision.c ft_do_star.c ft_printf_calloc.c\
			ft_printfdo.c ft_utils.c



OBJS	=	${SRCS:%.c=%.o}


FLAGS =  -Wall -Werror -Wextra -c

%.o: %.c
	gcc ${FLAGS} $< -o $@

all: ${NAME}

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS} ${OBJS_b}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
