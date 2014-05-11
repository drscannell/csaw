#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helper.h"

char* slice(char* str, int start, int len) {
	char* subset = malloc(len);
	int j = 0;
	for(int i = 0; i < len; i++) {
		j = start + i;
		subset[i] = str[j];
	}
	return subset;
}

char* readFile(char* path) {
	FILE *f;
	f = fopen(path, "r");
	int buffersize = 8;
	char* bytes = malloc(buffersize);
	int bytesread;
	int totalbytes = 0;
	char* str = "";
	char* hold;
	char* subset = "";
	while ((bytesread = fread(bytes, 1, buffersize, f)) > 0) {
		hold = malloc(strlen(str));
		hold = str;
		totalbytes += bytesread;
		str = malloc(totalbytes);
		strcat(str, hold);
		if (bytesread == buffersize) {
			strcat(str, bytes);
		} else {
			subset = slice(bytes, 0, bytesread);
			strcat(str, subset);
		}
	}
	fclose(f);
	return str;
}
