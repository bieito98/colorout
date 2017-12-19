#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "colorout.h"
#define FALSE 0
#define TRUE 1

int main (int argc, char * argv[]) {

	int x;
	int stop = FALSE;
	int count = 0;
	hex_color colv[8] = {
		BLACK, RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA, WHITE
	};
	hex_color hc;
	
	
	srandom(time(NULL));
	
	printf("This test program will show colors until one exactly matches:");
	printf(" BLACK, RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA or WHITE\n");
	printf("\nStarting in 5 seconds. Hit Ctrl+C to abort at any moment.\n");
	
	sleep(5);

	while (!stop) {
		hc = random() & 0xFFFFFF;
		x=0;
		while (x<8) {
			if (hc == colv[x]) {
				stop = 1;
				break;
			}
			x++;
		}
		printTest(hc);
		resetCol();
		printf(" ");
		count++;
		if (count % 10 == 0)
			printf("\n");
	}
	
	resetCol();
	printf("\n");
	printf("Colors tested: %d\n", count-1);

	return 0;
}
