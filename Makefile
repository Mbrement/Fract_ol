NAME	= fractol
SRCS	= Error/error.c \
Parser/parser_core.c \
fract_ol_core.c \

HEADERS		=	fract_ol.h
OBJS = $(patsubst %.c,%.o,$(SRCS))
CC			= cc
CCWFLAGS	= -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCWFLAGS) $^ -o $@

%.o : %.c $(HEADERS)
		$(CC) $(CCWFLAGS) -I. -c $< -o $@ 

clean : 
	-$(RM) $(OBJS)

fclean : clean
	-$(RM) $(NAME)

re : fclean all

normy:
	norminette $(SRCS)

.PHONY: all clean fclean re $(NAME)
