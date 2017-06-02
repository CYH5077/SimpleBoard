#ifndef __RESOURCE_HEADER__
#define __RESOURCE_HEADER__

#include "./resource/info.h"
#include "./r_type.h"

extern void get_resource_info(reInfo * re);
extern void printResource(reInfo re);

extern void font_color(int color);
extern void font_color_reset();

#define LINE 40
#define VERSION " Resource 0.1v "
void print_line(char print_char, int line);
#endif
