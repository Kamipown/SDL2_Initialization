NAME = SDL2_Initialization

SRC = main.c

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -lSDL2

clean:
	rm -f $(NAME)

re: clean all
