CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = lib
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(LIBFT) $(OBJ_DIR) push_swap

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

push_swap: $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re

