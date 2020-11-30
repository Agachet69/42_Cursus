NAME = libft.a

NAME2 = libft.a

SRCS	=	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
			ft_isascii.c ft_isprint.c ft_toupper.c ft_atoi.c\
			ft_tolower.c ft_bzero.c ft_memset.c ft_memcpy.c\
			ft_strchr.c ft_strrchr.c ft_memchr.c ft_memccpy.c\
			ft_strlcpy.c ft_strnstr.c ft_strncmp.c ft_memcmp.c\
			ft_memmove.c ft_strlcat.c ft_calloc.c ft_strdup.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c

SRCS_B	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c

OBJS	=	${SRCS:%.c=%.o}

OBJS_b	=	${SRCS_B:%.c=%.o}

FLAGS =  -Wall -Werror -Wextra -c 

%.o: %.c
	gcc ${FLAGS} $< -o $@

all: ${NAME}

${NAME} : ${OBJS} 
		ar rc ${NAME} ${OBJS} 

bonus: ${OBJS} ${OBJS_b}
				ar rc ${NAME} ${OBJS} ${OBJS_b}
		
clean: 
	rm -rf ${OBJS} ${OBJS_b}
	
fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re