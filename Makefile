# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 00:02:10 by mykman            #+#    #+#              #
#    Updated: 2022/07/20 17:14:23 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	@gcc
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address
RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
RESET			:=	\033[38;5;7m
PREFIX			=	[${YELLOW}${NAME}${RESET}]\t\t
# Variables
NAME			=	pipex
LIBFT_FOLDER	=	Libft/
LIBFT_NAME		=	libft.a
MAKE_LIBFT		=	@make -s -C ${LIBFT_FOLDER}
# Files
INCLUDES		=	-I./includes -I./${LIBFT_FOLDER}/includes
SRCS			=	main.c
OBJS			=	$(addprefix srcs/, ${SRCS:.c=.o})
# Rules
%.o:		%.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
	@echo "${PREFIX}Compilation of $<..."
$(NAME):	${OBJS}
	${MAKE_LIBFT}
	${CC} ${CFLAGS} ${INCLUDES} $^ ${LIBFT_FOLDER}/${LIBFT_NAME} -o $@
all:	$(NAME)
clean:
	${MAKE_LIBFT} clean
	@rm -f ${OBJS}
fclean:
	${MAKE_LIBFT} fclean
	@rm -f ${NAME} ${OBJS}
re:		fclean all
.PHONY:	all clean fclean re
