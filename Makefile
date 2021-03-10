SRC =	libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_ftoa.c\
		libft/ft_itoa.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_utoa.c\
		libft/ft_xtoa.c\
		libft/ft_ptoa.c\
		libftprintf/a_to_str.c\
		libftprintf/c_to_str.c\
		libftprintf/d_to_str.c\
		libftprintf/f_to_str.c\
		libftprintf/n_to_str.c\
		libftprintf/p_to_str.c\
		libftprintf/s_to_str.c\
		libftprintf/u_to_str.c\
		libftprintf/x_to_str.c\
		libftprintf/ft_is.c\
		libftprintf/get_precision.c\
		libftprintf/get_width.c\
		libftprintf/pad_char.c\
		libftprintf/print_buf.c\
		libftprintf/ft_printf.c

B_SRC =	libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_ftoa.c\
		libft/ft_itoa.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_utoa.c\
		libft/ft_xtoa.c\
		libft/ft_ptoa.c\
		libftprintf/a_to_str.c\
		libftprintf/c_to_str.c\
		libftprintf/d_to_str.c\
		libftprintf/f_to_str.c\
		libftprintf/n_to_str.c\
		libftprintf/p_to_str.c\
		libftprintf/s_to_str.c\
		libftprintf/u_to_str.c\
		libftprintf/x_to_str.c\
		libftprintf/ft_is.c\
		libftprintf/get_precision.c\
		libftprintf/get_width.c\
		libftprintf/pad_char.c\
		libftprintf/print_buf.c\
		libftprintf/ft_printf.c

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf

ifdef WITH_BONUS
	OBJ_SELECTED = $(B_OBJ)
else
	OBJ_SELECTED = $(OBJ)
endif

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 $(NAME)

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
