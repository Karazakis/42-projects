NAME = push_swap
SRC = main.c push_swap.c quick_sort.c push_swap_input.c utils.c phase_one.c phase_two.c phase_tree.c moves.c moves_utils.c
OBJ = $(SRC:.c=.o)
FLAGS = 

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
	@rm $(OBJ)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
