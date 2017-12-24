#ifndef COLOROUT_H_
#define COLOROUT_H_
#define WHITE 0xFFFFFF
#define BLACK 0X000000
#define GREY5 0X7F7F7F
#define RED 0XFF0000
#define YELLOW 0XFFFF00
#define GREEN 0X00FF00
#define CYAN 0X00FFFF
#define BLUE 0X0000FF
#define MAGENTA 0XFF00FF
#define TRYWORD 1
#define HEXONLY 0

typedef struct {
	unsigned short int r;
	unsigned short int g;
	unsigned short int b;
} color;

typedef unsigned long int hex_color;

color hexctoc (hex_color);
hex_color ctohexc (color);
color mixCol (color, color);
hex_color negativeCol (hex_color);
hex_color visiblewithCol (hex_color);
char hexctochar (hex_color);
char * hexctostr (hex_color, int);
void printCol (color);
void setBgCol (hex_color);
void setFgCol (hex_color);
void resetCol ();

void printTest (hex_color);

#endif
