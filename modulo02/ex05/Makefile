PROGRAM = m02ex05

SRC = $(PROGRAM).c schedule.c
OBJ = $(PROGRAM).o schedule.o
HEADERS = schedule.h

all: $(PROGRAM)

run: $(PROGRAM)
	@echo "Running $(PROGRAM)..."
	./$(PROGRAM)

$(PROGRAM): $(OBJ)
	@echo "Creating executable $(PROGRAM)."
	gcc $(OBJ) -o $(PROGRAM)

$(PROGRAM).o: $(PROGRAM).c $(HEADERS)
	@echo "Compiling $(PROGRAM).c..."
	gcc -c $(PROGRAM).c -o $(PROGRAM).o

schedule.o: schedule.c $(HEADERS)
	@echo "Compiling schedule.c..."
	gcc -c schedule.c -o schedule.o

clean:
	@echo "Removing files: $(OBJ) and $(PROGRAM)"
	rm -f $(OBJ) $(PROGRAM)
