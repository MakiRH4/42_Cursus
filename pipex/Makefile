# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 00:51:06 by fleonte           #+#    #+#              #
#    Updated: 2024/09/06 21:50:29 by fleonte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/exeggutor.c \
			src/pipex.c \
			src/pipex_utils.c \
			
SRCS_BONUS = 

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
RM = rm -f

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

FT_PRINTF = ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g

#------------------------------------------------------------------------------#

${NAME}: ${OBJS}
		make all -C libft/
		make all -C ft_printf/
		${CC} ${OBJS} ${LIBFT} ${FT_PRINTF} -o $(NAME)

${NAME_BONUS}: ${OBJS_BONUS}
		make all -C libft/
		make all -C ft_printf/
		${CC} ${OBJS_BONUS} ${LIBFT} ${FT_PRINTF} -o $(NAME_BONUS)

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
		make clean -C libft/
		make clean -C ft_printf/
		${RM} ${OBJS}

fclean: clean
		make fclean -C libft/
		make fclean -C ft_printf/
		${RM} ${NAME}

re: fclean all