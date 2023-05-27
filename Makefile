SRC_DIR = ./src
OBJ_DIR = ./obj
INCLUDE = ./includes
NAME = philo

SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/set_init_args.c \
	$(SRC_DIR)/set_dinner.c \
	$(SRC_DIR)/set_philo.c \
	$(SRC_DIR)/libft.c \
	$(SRC_DIR)/time.c 



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