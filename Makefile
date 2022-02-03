NAME		=	so_long

INCLUDES	=	includes/so_long_bonus.h

SRCS		=	srcs/main_bonus.c 			\
				srcs/free_bonus.c 			\
				srcs/init_bonus.c 			\
				srcs/key_control_bonus.c 	\
				srcs/map_check_bonus.c 		\
				srcs/map_create_bonus.c 	\
				srcs/map_info_bonus.c 		\
				srcs/render_bonus.c 		\
				srcs/check_bonus.c

DIR_MLX		=	./minilibx

DIR_LIBFT	=	./Libft

LIBFT		=	./Libft/libft.a

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

IFLAGS		=	-I. -I./minilibx -I./Libft

OBJS		=	${SRCS:%.c=%.o}

.PHONY:  	all clean fclean re bonus

all:		${NAME}

${NAME}:	${OBJS} ${INCLUDES}
	@${MAKE} -C ${DIR_LIBFT} all
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -L${DIR_MLX} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o:	%.c ${INCLUDES}
	@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}
	@${MAKE} -C ${DIR_LIBFT} clean

fclean:  	clean
	@${RM} ${NAME}
	@${MAKE} -C ${DIR_LIBFT} fclean

re:   		fclean all