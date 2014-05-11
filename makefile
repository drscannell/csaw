all: compile

compile:
	mkdir -p build
	gcc -o build/main -ansi src/*.c

test: compile
	build/main


