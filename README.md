# colorout

Colorout is a C library designed with the purpose of making easier the task of providing a coloured output. 

Foreground and background colours can be both set by their RGB value, coded as a hexadecimal number (0xRRGGBB: where RR stands for Red, GG for green and BB for blue values). 

It is defined a set of 9 default colours, as well as some useful functions (e.g. to get the negative colour, to get a visible colour, test functions ...). 

Its internal implementation relies on ANSI escape codes.
