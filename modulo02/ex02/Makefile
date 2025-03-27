all: m02ex02

m02ex02: m02ex02.o divide.o
	@echo "Creating executable."
	gcc m02ex02.o divide.o -o m02ex02

m02ex02.o: m02ex02.c divide.h
	@echo "Compiling main file."
	gcc -c m02ex02.c

divide.o: divide.c
	@echo "Compiling divide file."
	gcc -c divide.c

clean:
	@echo "Removing files."
	rm -f m02ex02.o divide.o m02ex02

run: m02ex02
	./m02ex02