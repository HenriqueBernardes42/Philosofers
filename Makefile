SRC_DIR = ./src
OBJ_DIR = ./obj
INCLUDE = ./includes
NAME = philo

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/actions.c \
	$(SRC_DIR)/dinner.c \
	$(SRC_DIR)/libft.c \
	$(SRC_DIR)/init_thread.c \
	$(SRC_DIR)/set_args.c \
	$(SRC_DIR)/set_philos.c \
	$(SRC_DIR)/set_table.c \
	$(SRC_DIR)/monitor.c \
	$(SRC_DIR)/utils.c 

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -Werror
CC = cc

all: dir $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  $(FLAGS) -I $(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

dir:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all dir clean fclean re