PROGRAM = m01ex12

run: $(PROGRAM)
	./$(PROGRAM)

all: $(PROGRAM)

$(PROGRAM): $(PROGRAM).o
	@echo "Creating executable."
	gcc $(PROGRAM).o -o $(PROGRAM)

$(PROGRAM).o: $(PROGRAM).c
	@echo "Compiling $(PROGRAM).c"
	gcc -c $(PROGRAM).c

clean:
	@echo "Removing files."
	rm -f $(PROGRAM).o $(PROGRAM)