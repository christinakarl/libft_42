# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 15:18:42 by nvaubien          #+#    #+#              #
#    Updated: 2023/05/23 20:21:07 by nvaubien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC						= gcc -g

CFLAGS					:= -Wall -Wextra -Werror

NAME					:= pipex

BONUS_NAME				:= pipex_bonus

LIB_DIRECTORY			:= ../libs/

LIBFT					:= $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY			:= $(LIB_DIRECTORY)libft/

LIBPRINTF				:= $(LIBPRINTF_DIRECTORY)libftprintf.a # /libs/libftprinf/libftprintf.a
LIBPRINTF_DIRECTORY		:= $(LIB_DIRECTORY)ftprintf/ #/libs/ftprintf

SOURCES_DIRECTORY		:= ./srcs/

SOURCES_LIST			:=	main.c					\
							parsing.c				\
							error-handling.c		\
							file-handling.c			\
							memory-handling.c		\
							get-access.c			\
							improved-syscalls.c		\
							execution.c				\
							linked-list.c			\
							helper-init.c			\
							helper-init2.c			\
							helper-init3.c			\

OBJECTS_DIRECTORY		:= objs/
OBJECTS_LIST			:= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS					:= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo compilating libft
	$(MAKE) -sC $(LIBFT_DIRECTORY)
	cp ../libs/libft/libft.a .

$(LIBPRINTF):
	echo "$(NAME): Creating $(LIBPRINTF)..."
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY)
	cp ../libs/ftprintf/libftprintf.a .

$(NAME): $(LIBFT) $(LIBPRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -L../libs/ftprintf -lftprintf -L../libs/libft -lft -o $(NAME)


SOURCES_DIRECTORY_BONUS		:= ./srcs_bonus/

SOURCES_LIST_BONUS			:=	main-bonus.c					\
							parsing-bonus.c				\
							error-handling-bonus.c		\
							file-handling-bonus.c			\
							memory-handling-bonus.c		\
							get-access-bonus.c			\
							improved-syscalls-bonus.c		\
							execution-bonus.c				\
							linked-list-bonus.c			\
							helper-init-bonus.c			\
							helper-init2-bonus.c			\
							helper-init3-bonus.c			\

OBJECTS_DIRECTORY_BONUS		:= objs_bonus/
OBJECTS_LIST_BONUS			:= $(patsubst %.c, %.o, $(SOURCES_LIST_BONUS))
OBJECTS_BONUS					:= $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_BONUS))

bonus: $(BONUS_NAME)

$(OBJECTS_DIRECTORY_BONUS):
	mkdir -p $(OBJECTS_DIRECTORY_BONUS)

$(OBJECTS_DIRECTORY_BONUS)%.o : $(SOURCES_DIRECTORY_BONUS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(LIBFT) $(LIBPRINTF) $(OBJECTS_DIRECTORY_BONUS) $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -L../libs/ftprintf -lftprintf -L../libs/libft -lft -o $(BONUS_NAME)

clean:
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)
	rm -rf $(OBJECTS_DIRECTORY_BONUS)

fclean: clean
	$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	$(MAKE) -sC $(LIBPRINTF_DIRECTORY) fclean
	rm -f libft.a
	rm -f libftprintf.a
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean re
