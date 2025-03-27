run: m02ex03
	./m02ex03

all: m02ex03

m02ex03: m02ex03.o
	@echo "Compiling executable."
	gcc m02ex03.o -o m02ex03

m02ex03.o: m02ex03.c
	@echo "Compiling m02ex03.o"
	gcc -c m02ex03.c

clean: 
	@echo "Removing files."
	rm -f m02ex03