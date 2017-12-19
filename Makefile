test: tester.c colorout.o
	gcc -Wall -o test colorout.o tester.c
showcolor: showcolor.c colorout.o
	gcc -Wall -o showcolor colorout.o showcolor.c
debug:
	gcc -Wall -o test colorout.o tester.c -g
clean:
	rm *.o
