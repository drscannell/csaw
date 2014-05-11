#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "helper.h"

void testReadFile() {
	char path[] = "src/tests/test-file-1.txt";
	char* str = readFile(path);
	str = slice(str, 0, strlen(str) - 1);
	assert(strcmp(str, "spam") == 0);
	printf("\ntestReadFile passed.\n");
}

void displayFile(char* path) {
	// remove trailing carriage return
	char* str = readFile(path);
	int totalBytes = strlen(str);
	str = slice(str, 0, strlen(str) - 1);
	printf("\n-----------\n\n");
	printf("%s", str);
	printf("\n\n-----------\n");
	printf("\ntotal bytes: %i\n", totalBytes);
}

int main(int argc, char *argv[]) {
	/*
	printf("\n# display files\n");
	for(int i = 1; i < argc; i++) {
		printf("\n## %s\n", argv[i]);
		displayFile(argv[i]);
	}
	*/
	testReadFile();
	printf("\n");
}
