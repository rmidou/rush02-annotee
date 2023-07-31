CC = cc -Wall -Werror -Wextra
EXEC = rush-02
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

%.o : %.c
	$(CC) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
