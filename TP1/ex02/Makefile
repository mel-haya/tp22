NAME = matrice

FILES = matrice.cpp

OBJ	= matrice.o

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(OBJ) main.cpp -o $(NAME)

$(OBJ):
	clang++ -c $(FILES) -o $(OBJ)

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
