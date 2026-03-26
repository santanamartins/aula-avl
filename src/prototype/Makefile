CC = gcc -Wall -pedantic

build_dir: 
	mkdir -p build

element: build_dir
	$(CC) -c -o build/element.o element.c

node: element
	$(CC) -c -o build/node.o node.c

rotations: node
	$(CC) -c -o build/rotations.o rotations.c

test_ll: rotations
	$(CC) -o build/test_ll build/node.o build/element.o build/rotations.o test_ll.c

test_rr: rotations
	$(CC) -o build/test_rr build/node.o build/element.o build/rotations.o test_rr.c

test_lr: rotations
	$(CC) -o build/test_lr build/node.o build/element.o build/rotations.o test_lr.c

test_rl: rotations
	$(CC) -o build/test_rl build/node.o build/element.o build/rotations.o test_rl.c

run_avl: test_avl
	./build/test_avl

clean:
	rm -rf build