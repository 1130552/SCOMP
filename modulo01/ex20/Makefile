PROGRAM = m01ex20

run: $(PROGRAM)
	@echo "Running $(PROGRAM)..."
	@./$(PROGRAM)

all: $(PROGRAM)

$(PROGRAM): $(PROGRAM).o
	@echo "Creating executable $(PROGRAM)..."
	gcc $(PROGRAM).o -o $(PROGRAM)

$(PROGRAM).o: $(PROGRAM).c
	@echo "Compiling $(PROGRAM).c..."
	gcc -c $(PROGRAM).c

clean:
	@echo "Cleaning up..."
	rm -f $(PROGRAM).o $(PROGRAM)
