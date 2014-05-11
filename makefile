
displayfile:
	mkdir -p build
	gcc -o build/displayfile -ansi src/helper/*.c src/argtests/*.c
	build/displayfile src/tests/test-file-1.txt src/tests/test-file-2.txt

test:
	mkdir -p build
	gcc -o build/test -ansi src/helper/*.c src/tests/*.c
	build/test


