/* ************************************************************************** */
/*                                                                          * */
/*                             MAKEFILE PUSH_SWAP                           * */
/*                                                                          * */
/* ************************************************************************** */

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = src
INC = inc/push_swap.h

/* ************************************************************************** */
/* ******************************Source files******************************* */
/* ************************************************************************** */

FILES = ${SRC_DIR}/push_swap.c \

OBJ = ${FILES:.c=.o}

/* ************************************************************************** */
/* **********************************MAKE************************************ */
/* ************************************************************************** */

all: $(NAME)

$(NAME): $(OBJ) $(INC) Makefile
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "🤖 $(NAME) 🤖 PROGRAM CREATED ✅"

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f ${OBJ}
	@echo "$(NAME) extra files removed. 🗑️"

fclean: clean
	make -C libft fclean
	rm -f ${NAME}
	@echo "$(NAME) has been bulldozed. 💣"

re: fclean all

.PHONY: all clean fclean re