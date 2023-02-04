NAME		=	fract_ol

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

DIR_OBJS	=	./

DIR_SRCS	=	./

DIR_MLX		=	Mini_libx/

DIR_LIBFT	=	Tools/Libft/

HEAD	=	fract_ol.h

SRCS	=	Error/error.c \
			Parser/parser_core.c \
			Project_core/algo_core.c\
			fract_ol_core.c\


OBJS	=	${SRCS:%.c=${DIR_OBJS}%.o}


CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror


RM		=	rm -rf
MKDIR	=	mkdir -p


all		:	${NAME}


${NAME}	:	${OBJS} Makefile ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_MLX}, ${LIBMLX}}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft -L${DIR_MLX} -lmlx -lXext -lX11

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
			make ${LIBFT} -C ${DIR_LIBFT}

${addprefix ${DIR_MLX}, ${LIBMLX}}	:
			make ${LIBMLX} -C ${DIR_MLX}



${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile so_long.h ./libft/headers/ft_printf.h ./libft/headers/get_next_line_bonus.h ./libft/headers/libft.h | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${addprefix ${DIR_LIBFT}, headers/} -I ${DIR_MLX} -I. -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}


fclean_lib		:
					make fclean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

clean			:	fclean_lib
					${RM} ${OBJS}

fclean			:	clean
					${RM} ${NAME}

fclean_all		:	fclean fclean_lib

re				:	fclean
					${MAKE} all

.PHONY:	all clean fclean re fclean_lib fclean_all