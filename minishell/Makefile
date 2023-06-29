# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 12:26:42 by ckarl             #+#    #+#              #
#    Updated: 2023/06/29 18:50:52 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c built-in_others.c built-in_env.c list_helpers.c \
				list_helpers2.c bubble_sort.c

OBJS			= ${SRCS:.c=.o}

HEADER  		= minishell.h

LIBS			= -Llibs/ftprintf -lftprintf -Llibs/libft -lft \
					-L/Users/ckarl/homebrew/Cellar/readline/8.2.1/lib -lreadline

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
				cd libs/libft; make bonus
				cd libs/ftprintf; make all
				cd pipex; make bonus
				${CC} ${CFLAGS} ${LIBS} ${OTH_HEAD} -o $@ ${OBJS}

clean:
				${RM} ${OBJS}
				# cd libs/libft; make clean
				# cd libs/ftprintf; make clean
				# cd pipex; make clean

fclean:			clean
				${RM} ${NAME}
				# cd libs/libft; make fclean
				# cd libs/ftprintf; make fclean
				# cd pipex; make fclean
				@echo "$(COLOUR_VIO)All clean!$(COLOUR_END)"

re:				fclean all

.PHONY:			all clean fclean re


