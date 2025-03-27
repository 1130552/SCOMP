PROGRAM = m01ex15

SRC = $(PROGRAM).c execute.c
OBJ = $(PROGRAM).o execute.o
HEADERS = execute.h

all: $(PROGRAM)

run: $(PROGRAM)
	@echo "Running $(PROGRAM)..."
	./$(PROGRAM)

$(PROGRAM): $(OBJ)
	@echo "Creating executable $(PROGRAM)."
	gcc $(OBJ) -o $(PROGRAM)

$(PROGRAM).o: $(PROGRAM).c $(HEADERS)
	@echo "Compiling $(PROGRAM).c and execute.c"
	gcc -c $(PROGRAM).c -o $(PROGRAM).o
	gcc -c execute.c -o execute.o

clean:
	@echo "Removing files: $(OBJ) and $(PROGRAM)"
	rm -f $(OBJ) $(PROGRAM)
