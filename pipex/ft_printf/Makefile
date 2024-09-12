SRCS        :=      printf_c.c \
                    printf_s.c \
                    printf_p.c \
                    ft_printf.c \
                    printf_x.c \
                    printf_d_i.c \
                    printf_u.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
                        
NAME = libftprintf.a

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