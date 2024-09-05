# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floris <floris@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 00:51:06 by fleonte           #+#    #+#              #
#    Updated: 2023/09/29 23:55:32 by floris           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strnstr.c ft_isdigit.c ft_putstr_fd.c ft_strlcpy.c ft_strlen.c \
	ft_memcmp.c ft_putnbr_fd.c ft_strchr.c ft_bzero.c ft_strjoin.c \
	ft_isascii.c ft_memcpy.c ft_isprint.c ft_toupper.c ft_strrchr.c \
	ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_memset.c ft_substr.c \
	ft_strncmp.c ft_strtrim.c ft_memmove.c ft_strlcat.c ft_calloc.c \
	ft_strdup.c ft_atoi.c ft_isalnum.c ft_tolower.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putendl_fd.c ft_split.c
OBJS = ${SRCS:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all