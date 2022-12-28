SRCS		= srcs/ft_printf.c srcs/ft_printbasics.c srcs/ft_printptr.c srcs/ft_printhex.c srcs/ft_itoa_u.c \
			srcs/ft_itoa.c srcs/ft_printnbr.c

OBJS		= ${SRCS:.c=.o}

HEADER		= include/ft_printf.h

NAME		= ft_printf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I${HEADER}

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
