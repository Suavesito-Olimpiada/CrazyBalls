#ifndef _SCREEN_H
#define _SCREEN_H

#include <ncurses.h>

#include "matrix.h"

int _ymax=0, _xmax=0;

typedef matrix screen; /* es mas facil pensar en pantallas que en matrices */

/* redefinir para el "nuevo" tipo de dato screen */
void (*fscanf_screen) (screen m, FILE *pf) = fscanf_matrix;

void (*fprintf_screen) (matrix m, FILE *pf) = fprintf_matrix;

void (*create_screen) (matrix *m, int ren, int col) = create_matrix;

void (*free_screen) (matrix *m) = free_matrix;

void _print_screen (screen s, int ymax, int xmax);

#define print_screen (s) = _print_screen (s, (s.ren>_ymax)?_ymax:s.ren, (s.col>_xmax)_xmax:s.col)

#endif
