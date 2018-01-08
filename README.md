# colorout

Colorout is a C library designed with the purpose of making easier the task of providing a colored output.

Foreground and background colors can be both set by their RGB value, coded as a hexadecimal number (0xRRGGBB; where RR stands for Red, GG for green and BB for blue values).

It is defined a set of 9 default colors, as well as some useful functions (e.g. to get the negative color, to get a visible color, test functions, ... ).

Its internal implementation relies on ANSI escaping codes.
