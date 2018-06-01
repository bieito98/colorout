#include "colorout.h"
#include <stdio.h>
#include <string.h>

color hexctoc (hex_color c) {
	color aux;
	
	if (c<=0xFFFFFF) {
		aux.r=c>>16;
		aux.g=(c&0x00FF00)>>8;
		aux.b=c&0x0000FF;
	}
	else {
		aux.r=0;
		aux.g=0;
		aux.b=0;
	}
	return aux;
}

hex_color ctohexc (color c) {
	return ((c.r<<16) + (c.g<<8) + (c.b));
}

/* BETTER IMPLEMENTATION NEEDED
color mixCol (color a, color b) {
	color c;
	
	c.r = (a.r + b.r)>>1;
	c.g = (a.g + b.g)>>1;
	c.b = (a.b + b.b)>>1;
	
	return c;
} 
*/

hex_color negativeCol (hex_color hc) {
	return (0xFFFFFF-hc);

}

hex_color visiblewithCol (hex_color hc) {
	color c;
	
	c = hexctoc(hc);
	
	if ( (c.r+c.b+c.g)/3 > 0x7F) 
		return BLACK;
	else
		return WHITE;
}

char hexctochar (hex_color hc) {
	char aux;
	hex_color xc;

	xc = hc & 0xFFFFFF;
	switch (xc) {
		case WHITE:   aux='W'; break;
		case BLACK:   aux='K'; break;
		case RED:     aux='R'; break;
		case YELLOW:  aux='Y'; break;
		case GREEN:   aux='G'; break;
		case CYAN:    aux='C'; break;
		case BLUE:    aux='B'; break;
		case MAGENTA: aux='M'; break;
		case GREY5:   aux='g'; break;
		default:      aux='#';
	}

	return aux;	
}

char * hexctostr (hex_color hc, int mode) {
	char * aux;
	char str[8];
	hex_color xc;
	
	xc = hc & 0xFFFFFF;
	if (!mode) {
		sprintf(str, "#%06lX", xc);
		aux = str;
	} 
	else {
		switch (xc) {
			case WHITE:   aux = "WHITE  "; break;
			case BLACK:   aux = "BLACK  "; break;
			case RED:     aux = "RED    "; break;
			case YELLOW:  aux = "YELLOW "; break;
			case GREEN:   aux = "GREEN  "; break;
			case CYAN:    aux = "CYAN   "; break;
			case BLUE:    aux = "BLUE   "; break;
			case MAGENTA: aux = "MAGENTA"; break;
			case GREY5:   aux = "GREY05 "; break;
			default:      return hexctostr(xc,0);
		}
	}
	
	return aux;

}

void printCol (hex_color hc) {
	color c;

	c=hexctoc(hc);
	printf("    R    G    B\n");
	printf("%5hd", c.r);
	printf("%5hd", c.g);
	printf("%5hd\n", c.b);
}

void setBgCol (hex_color hc) {
	color c;
	char r[4];
	char b[4];
	char g[4];
	
	c=hexctoc(hc);
	sprintf(r, "%hd", c.r);
	sprintf(g, "%hd", c.g);
	sprintf(b, "%hd", c.b);
	printf("\x1b[48;2;");
	printf("%s;", r);
	printf("%s;", g);
	printf("%sm", b);

}

void setFgCol (hex_color hc) {
	color c;
	char r[4];
	char b[4];
	char g[4];
	
	c=hexctoc(hc);
	sprintf(r, "%hd", c.r);
	sprintf(g, "%hd", c.g);
	sprintf(b, "%hd", c.b);
	printf("\x1b[38;2;");
	printf("%s;", r);
	printf("%s;", g);
	printf("%sm", b);
}

void resetCol () {
	printf("\x1b[0m");
}

void printTest(hex_color hc) {
	setBgCol(hc);
	setFgCol(visiblewithCol(hc));
	printf("%s", hexctostr(hc, TRYWORD));
	resetCol();
}
