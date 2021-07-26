NAME	=	bsq

INC		=	includes

SRCS	=	./srcs/*.c

OBJS	=	./*.o

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -I ${INC} -c ${SRCS} 
	
${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${OBJS}:		${SRCS}
	${CC} ${CFLAGS} -I ${INC} -c ${SRCS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
