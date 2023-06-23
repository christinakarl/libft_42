# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 12:26:42 by ckarl             #+#    #+#              #
#    Updated: 2023/06/23 15:26:44 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c

OBJS			= ${SRCS:.c=.o}

HEADER  		= minishell.h

LIBS			= -Llibs/libft -lft -Llibs/ftprintf -lftprintf

OTH_HEAD		= -Ilibft -Ift_printf

NAME			= minishell

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

COLOUR_GREEN	=\033[1;32m
COLOUR_RED		=\033[0;31m
COLOUR_YELL		=\033[0;33m
COLOUR_TURQ		=\033[1;36m
COLOUR_WHITE	=\033[1;37m
COLOUR_BLUE		=\033[1;34m
COLOUR_VIO		=\033[1;35m
COLOUR_END		=\033[0m

%.o: %.c
				${CC} -c ${CFLAGS} $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
				cd libs/libft; make all
				cd libs/ftprintf; make all
				${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS} ${OTH_HEAD}
				cd pipex; make all
				@echo "$(COLOUR_GREEN)( ಠ ͜ʖ ಠ )$(COLOUR_END)"

clean:
				${RM} ${OBJS}
				cd libs/libft; make clean
				cd libs/ftprintf; make clean

fclean:			clean
				${RM} ${NAME}
				cd libs/libft; make fclean
				cd libs/ftprintf; make fclean
				@echo "$(COLOUR_VIO)All clean!$(COLOUR_END)"

re:				fclean all

.PHONY:			all clean fclean re


