NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -L./minilibx -lmlx -framework AppKit -framework OpenGL
SRCS = $(wildcard *.c) $(wildcard getnextline/*.c)
OBJS= $(SRCS:.c=.o)
PRIN = ./ft_printf/libftprintf.a
MINI = ./minilibx/libmlx.a

all: $(PRIN)  ${NAME}
	
$(PRIN):
	make -C ./ft_printf

$(MINI):
	make -C ./minilibx

$(NAME): $(OBJS) $(MINI) $(PRIN)
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME) $(PRIN)

.c.o:
	${CC} -c $^ -o $@

clean: 
	rm -rf ${OBJS}
	make clean -C ft_printf/

fclean: clean
	rm -rf ${NAME}
	make fclean -C ft_printf/
	make clean -C minilibx/

re: fclean all

norm:
	norminette ekler.c freeler.c imgs.c main.c maps.c player.c so_long.h ft_itoa.c ft_split.c ft_strdup.c ft_strjoin.c ft_strnstr.c

.PHONY: fclean re all clean