
NAME = push_swap
CC = cc 
CFLAGS = -Wall -Werror -Wextra


SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

HEADERS =	${INC_DIR}/push_swap.h \
			${INC_DIR}/structures.h 

FILES = ${SRC_DIR}/push_swap.c 

OBJ = ${FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) Makefile
	@make -C libft --no-print-directory
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "🤖$(COLOUR_BLUE) $(NAME) 🤖 $(COLOUR_GREEN)PROGRAM CREATED $(COLOUR_END)✅"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean --no-print-directory
	@rm -f ${OBJ}
	@echo "$(COLOUR_BLUE)$(NAME) extra files removed. $(COLOUR_END)🗑️"

fclean: clean
	@make -C libft fclean --no-print-directory
	@rm -f ${NAME}
	@echo "$(COLOUR_RED)$(NAME) program has been bulldozed. $(COLOUR_END)💣"

re: fclean all

.PHONY: all clean fclean re