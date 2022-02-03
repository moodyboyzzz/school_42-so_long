NAME			= 	libft.a

SRCS			=	ft_strdup.c ft_strlen.c ft_itoa.c

OBJS			= 	${SRCS:%.c=%.o}

CC				= 	gcc

RM				= 	rm -f

CFLAGS			= 	-Wall -Wextra -Werror

INCLUDES		= 	libft.h

.PHONY:			all clean fclean re bonus

all:			${NAME}

${NAME}:		${OBJS}
				@ar rcs ${NAME} ${OBJS}
				@ranlib ${NAME}

%.o:	%.c ${INCLUDES}
				@${CC} ${CFLAGS} -c $< -o $@

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all