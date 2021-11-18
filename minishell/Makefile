# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 14:10:39 by agachet           #+#    #+#              #
#    Updated: 2021/06/24 18:40:57 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRCS_PATH	=	srcs

SRCS_NAME	=	main.c utils.c ft_path.c ft_builtin.c ft_list.c ft_export.c \
				ft_unset.c ft_exec.c

OBJS		=	$(PATH:.c=.o)

FLAGS		=	-Wall -Werror -Wextra

PATH		=	$(addprefix $(SRCS_PATH)/,$(SRCS_NAME))

%.o:		%.c ./include/minishell.h
			gcc $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(FLAGS) $(OBJS) -o $(NAME) -lreadline

clean:
			rm -f $(OBJS)

fclean:
			rm -f $(OBJS) $(NAME)

re:			fclean all

norme:
			@norminette $(PATH) include/minishell.h

.PHONY:		re all norme clean fclean
