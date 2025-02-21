# **************************************************************************** #
# *                                                                          * #
# *                               MAKEFILE 🔨                                * #
# *                            ⛓️ PUSH_SWAP ⛓️                               * #
# *                                                                          * #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Werror -Wextra

# **************************************************************************** #
# **********************************COLORS************************************ #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_BLACK=\033[0;30m
COLOUR_YELLOW=\033[0;33m
COLOUR_PURPLE=\033[0;35m
COLOUR_CYAN=\033[0;36m

COLOUR_BRIGHT_BLACK=\033[1;30m
COLOUR_BRIGHT_RED=\033[1;31m
COLOUR_BRIGHT_GREEN=\033[1;32m
COLOUR_BRIGHT_YELLOW=\033[1;33m
COLOUR_BRIGHT_BLUE=\033[1;34m
COLOUR_BRIGHT_PURPLE=\033[1;35m
COLOUR_BRIGHT_CYAN=\033[1;36m

# **************************************************************************** #
# *******************************DIRECTORIES********************************** #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build

# **************************************************************************** #
# *********************************HEADERS************************************ #
# **************************************************************************** #

HEADERS =	${INC_DIR}/push_swap.h \
			${INC_DIR}/structures.h 

# **************************************************************************** #
# ********************************SRC FILES*********************************** #
# **************************************************************************** #

FILES = ${SRC_DIR}/push_swap.c \
		${SRC_DIR}/errors.c \

OBJ = ${FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

# **************************************************************************** #
# **********************************MAKE************************************** #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) Makefile
	@make -C libft --no-print-directory
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "🤖$(COLOUR_PURPLE) $(NAME) 🤖 $(COLOUR_GREEN)PROGRAM CREATED ✅$(COLOUR_END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ]; then rm -r $(OBJ_DIR); fi
	@make -C libft clean --no-print-directory
	@rm -f ${OBJ}
	@echo "🤖 $(COLOUR_PURPLE)$(NAME) 🤖$(COLOUR_CYAN) EXTRA FILES REMOVED. $(COLOUR_END)🗑️"

fclean: clean
	@make -C libft fclean --no-print-directory
	@rm -f ${NAME}
	@echo "$(COLOUR_PURPLE)🤖 $(NAME) 🤖 $(COLOUR_RED)PROGRAM BULLDOZED. $(COLOUR_END)💣"

re: fclean all

.PHONY: all clean fclean re