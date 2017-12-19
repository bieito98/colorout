#include "colorout.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
	int i;
	hex_color hc;

	if (argc > 1) {
		i = 1;
		while (i<argc) {
			hc = (hex_color) strtoul(argv[i], NULL, 16) & 0xFFFFFF;
			printTest(hc);
			printf(" ");
			i++;
		}
		printf("\n");
	} else
		printf("Usage: showcolor <hex_value_1> ... <hex_value_n>\n");

	return 0;
}
