# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 21:06:37 by fleonte           #+#    #+#              #
#    Updated: 2024/09/06 21:58:30 by fleonte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        =      printf_c.c \
                    printf_s.c \
                    printf_p.c \
                    ft_printf.c \
                    printf_x.c \
                    printf_d_i.c \
                    printf_u.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

NAME = libftprintf.a

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
                        


#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(RM) $(NAME)
	cp $(LIBFT)	$(NAME)
	ar rcs $(NAME)	$(OBJS)


$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft