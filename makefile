compile:
	gcc -o build/main -ansi src/*.c

test:
	gcc -o build/main -ansi src/*.c
	build/main test-files/test-file-1.txt test-files/test-file-2.txt

