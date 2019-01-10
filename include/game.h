#ifndef _GAME_H
#define _GAME_H

#include <ncurses.h>
#include <unistd.h>

#include "screen.h"
#include "particle.h"

typedef struct GAME {
    screen scr;
    particle *ps;
    int level;
} game;

typedef particle player;

const int level_settings [] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

void update_screen_particles (screen s, particle *ps, int n) {
    int i=0, j=0, x, y;
    for (i=0; i<s.ren; i++) {
        for (j=0; j<s.col; j++) {
            s.ptr [i][j] = "\0";
        }
    }
    for (i=0; i<n; i++) {
        x = ps [i].x;
        y = ps [i].y;
        s.ptr [y][x] = "o";
    }
}

int update_screen_player (screen s, player ply) {
    int stt = (s.ptr [ply.y][ply.x] != '\0')? 1: 0;
    s.ptr [ply.y][ply.x] = "x";
    return stt;
}

game init_game (int ymax, int xmax) {
    create_screen (&scr, ymax, xmax);
    particle
}


#endif
