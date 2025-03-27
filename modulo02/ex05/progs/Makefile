PROGS = prog1 prog2 prog3 prog4 prog5

all: $(PROGS)

$(PROGS): %: %.o
	@echo "Creating executable $@..."
	gcc $@.o -o $@

%.o: %.c
	@echo "Compiling $<..."
	gcc -c $<

run: $(PROGS)
	@echo "Running all programs..."
	@for prog in $(PROGS); do ./$$prog; done

clean:
	@echo "Cleaning up..."
	rm -f $(PROGS) *.o
