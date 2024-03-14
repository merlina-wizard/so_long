PROG    = so_long

SRCS    =	main.c maps/maps_validation.c \
			maps/maps_validation2.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c \
			put_image.c \
			set_structures.c \
			movement.c \
			robe.c \
			movement2.c \
			close.c \

OBJS     = ${SRCS:.c=.o}
MAIN    = main.c

HEADER    = -Iinclude

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g

.c.o:        %.o : %.c
	@gcc ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

all:         ${PROG}

${PROG}:    ${OBJS}
						@echo "\033[33m----Compiling lib----"
						@$(CC) ${OBJS} -lmlx -lXext -lX11 -L mlx -o ${PROG} ft_printf/libftprintf.a
						@echo "\033[32mSo Long Compiled!\n"

clean:
						@rm -f ${OBJS}


fclean:     clean
						@rm -f $(NAME)
						@rm -f ${PROG}
						@echo "\n\033[31mDeleting EVERYTHING!\n"

git:
	git add .
	git commit -m "update"
	git push

re:            fclean all

.PHONY: all clean fclean re
