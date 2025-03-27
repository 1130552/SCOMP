all: m01ex11

m01ex11: m01ex11.o create_twins.o
	@echo "Creating executable."
	gcc m01ex11.o create_twins.o -o m01ex11

m01ex11.o: m01ex11.c create_twins.h
	@echo "Compiling m01ex11.c"
	gcc -c m01ex11.c

create_twins.o: create_twins.c
	@echo "Compiling create twins."
	gcc -c create_twins.c

clean:
	@echo "Removing files."
	rm -f m01ex11.o create_twins.o m01ex11 