CC = gcc -Wall -pedantic

build_dir:
	mkdir -p build

element: build_dir
	$(CC) -c -o build/element.o element.c

node: element
	$(CC) -c -o build/node.o node.c

rotations: node
	$(CC) -c -o build/rotations.o rotations.c

avl: rotations
	$(CC) -c -o build/avl.o avl.c

main: avl
	$(CC) -o build/main main.c build/avl.o build/element.o build/rotations.o build/node.o

clean:
	rm -rf build