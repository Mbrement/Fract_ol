NAME		=	fractol

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
			Project_core/hook.c\
			Project_core/ft_color.c\
			fract_ol_core.c\
			Fractal/julia.c \
			Fractal/mandelbrot.c\
			Fractal/math.c\

OBJS	=	${SRCS:%.c=${DIR_OBJS}%.o}


CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror 
#-O3 -g -pg #-fsanitize=address -g3


RM		=	rm -rf
MKDIR	=	mkdir -p


all		:	${NAME}


${NAME}	:	${OBJS} ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_MLX}, ${LIBMLX}}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft -L${DIR_MLX} -lmlx -lXext -lX11

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
			make ${LIBFT} -C ${DIR_LIBFT}

${addprefix ${DIR_MLX}, ${LIBMLX}}	:
			make ${LIBMLX} -C ${DIR_MLX}



${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEAD} | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${addprefix ${DIR_LIBFT}, headers/} -I ${DIR_MLX} -I. -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}


fclean_lib		:
					make fclean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

clean			:	fclean_lib
					${RM} ${OBJS}

fclean			:	clean fclean_bonus fclean_lib
					${RM} ${NAME}

re				:	fclean
					${MAKE} all
normy:
	norminette $(SRCS)

bonus			: 
					make -C ./Bonus
clean_bonus		: 
					make clean -C ./Bonus
fclean_bonus		: 
					make clean -C ./Bonus
					make fclean -C ./Bonus

.PHONY:	all clean fclean re fclean_lib fclean_all normy bonus clean_bonus fclean_bonus