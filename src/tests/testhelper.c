#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../helper/helper.h"
#include "../minunit/minunit.h"

int tests_run = 0;

char* testReadFile() {
	char paths[] = {"src/tests/test-file-1.txt"};
	char* path;
	path = &paths[0];
	char* str = readFile(path);
	str = slice(str, 0, strlen(str) - 1);
	mu_assert("error", strcmp(str, "spam") == 0);
	return 0;
}

static char* all_tests() {
	mu_run_test(testReadFile);
	return 0;
}

int main(int argc, char **argv) {
	printf("\n### unit test results ###\n");
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n\n", tests_run);

	return result != 0;
}
