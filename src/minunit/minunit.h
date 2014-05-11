// http://www.jera.com/techinfo/jtns/jtn002.html

#define mu_assert(message, test) do { \
	if (!(test)) { \
		return message; \
	} \
} while (0)

#define mu_run_test(test, input, expected) do { \
	char *message = test(input, expected); \
	tests_run++; \
	if (message) { \
		return message; \
	} \
} while (0)

extern int tests_run;
