SRC =	ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_printf.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\

B_SRC =	ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_printf.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

NAME = libft.a
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