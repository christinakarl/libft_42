# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 13:33:18 by ckarl             #+#    #+#              #
#    Updated: 2022/11/25 13:33:26 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= print_decide.c ft_put_c.c ft_put_di.c ft_put_ptr.c ft_put_s.c ft_put_u.c ft_put_x.c ft_printf.c

OBJS		= ${SRCS:.c=.o}

HEADER		= ft_printf.h

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I${HEADER}

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
