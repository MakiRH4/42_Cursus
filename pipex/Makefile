# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 00:51:06 by fleonte           #+#    #+#              #
#    Updated: 2024/10/17 23:44:47 by fleonte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/exeggutor.c \
			src/pipex.c \
			src/pipex_utils.c 
			
SRCS_BONUS	=	src_bonus/exeggutor.c \
				src_bonus/pipex_bonus_utils.c \
				src_bonus/pipex_bonus.c \
				src_bonus/here_doc.c \
				get_next_line/get_next_line.c  \
				get_next_line/get_next_line_utils.c

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
		${CC} ${OBJS} ${LIBFT} ${FT_PRINTF} ${CFLAGS} -o $(NAME)

${NAME_BONUS}: ${OBJS_BONUS}
		make all -C libft/
		make all -C ft_printf/
		${CC} ${OBJS_BONUS} ${LIBFT} ${FT_PRINTF} ${CFLAGS} -o $(NAME_BONUS)

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
		make clean -C libft/
		make clean -C ft_printf/
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		make fclean -C libft/
		make fclean -C ft_printf/
		${RM} ${NAME} ${NAME_BONUS}

re: fclean all