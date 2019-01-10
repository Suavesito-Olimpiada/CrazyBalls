#include "screen.h"

void _print_screen (screen s, int ymax, int xmax) {
    int i=0, j=0;
    for (i=0; i<ymax; i++) {
        for (j=0; j<xmax; j++) {
            mvprintw (i, j, "%c", s.ptr [i][j]);
        }
    }
}
