#ifndef COLOROUT_H_
#define COLOROUT_H_
#define WHITE   0xFFFFFF
#define BLACK   0X000000
#define GREY5   0X7F7F7F
#define RED     0XFF0000
#define YELLOW  0XFFFF00
#define GREEN   0X00FF00
#define CYAN    0X00FFFF
#define BLUE    0X0000FF
#define MAGENTA 0XFF00FF
#define TRYWORD 1
#define HEXONLY 0

typedef struct {
	unsigned short int r;
	unsigned short int g;
	unsigned short int b;
} color;

typedef unsigned long int hex_color;

/* TYPE CONVERSION */
color hexctoc (hex_color);
hex_color ctohexc (color);


/* OUTPUT MANAGEMENT */
void setBgCol (hex_color);
void setFgCol (hex_color);
void resetCol ();


/* OTHER FUNCTIONS */

/* returns color in negative */
hex_color negativeCol (hex_color);

/* returns BLACK or WHITE depending on brightness */
hex_color visiblewithCol (hex_color);

/* tries to return a char representation of the color; '#' on failure */
char hexctochar (hex_color);

/* tries to convert a color to HTML-like representation. If mode == TRYWORD, and
*  color belongs to the defined above, its string name is returned */
char * hexctostr (hex_color, int mode);


/* TEST FUNCTIONS */

/* prints red, green and blue numeric values */
void printCol (hex_color);

/* prints a sample */
void printTest (hex_color);

#endif
