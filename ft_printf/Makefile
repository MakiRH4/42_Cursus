NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS        :=      printf_i.c \
                    printf_d.c \
                    ft_printf.c \
                    printf_x.c \
                    printf_s.c \
                    printf_p.c \
                          
OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

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