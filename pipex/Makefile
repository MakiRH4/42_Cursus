# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 00:51:06 by fleonte           #+#    #+#              #
#    Updated: 2024/09/05 02:23:56 by fleonte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = exeggutor2.c	exeggutor.c	main.c	pipex_utils.c
SRCS_BONUS = 
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
NAME = pipex 
NAME_BONUS = pipex_bonus
CC = cc
RM = rm -f
LIB = Libft/libft.a
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
		make all -C Libft/
		${CC} ${OBJS} $(LIB) -o $(NAME)

${NAME_BONUS}: ${OBJS_BONUS}
		make all -C Libft/
		${CC} ${OBJS_BONUS} $(LIB) -o $(NAME_BONUS)

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
		make clean -C Libft/
		${RM} ${OBJS}

fclean: clean
		make fclean -C Libft/
		${RM} ${NAME}

re: fclean all