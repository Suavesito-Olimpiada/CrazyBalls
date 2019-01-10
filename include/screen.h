#ifndef _SCREEN_H
#define _SCREEN_H

#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct SCREEN {
    int col;
    int ren;
    char** ptr;
} screen;

void fscanf_screen (screen m, FILE *fp);

void fprintf_screen (screen m, FILE *pf);

void create_screen (screen *m, int ren, int col);

void free_screen (screen *m);

void _print_screen (screen s, int ymax, int xmax);

#define print_screen(s) _print_screen(s,(s.ren>_ymax)?_ymax:s.ren,(s.col>_xmax)?_xmax:s.col)

#endif
