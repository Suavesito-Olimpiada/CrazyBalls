#ifndef _GAME_H
#define _GAME_H

#include <stdbool.h>

#include "screen.h"
#include "particle.h"

typedef struct GAME {
    screen scr;
    particle ply;
    particle *pls;
    int level;
} game;

game stdgame;

const int level_settings [] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};

void clear_screen (screen s) {
    int i=0, j=0;
    for (i=0; i<s.ren; i++) {
        for (j=0; j<s.col; j++) {
            s.ptr [i][j] = '\0';
        }
    }
}

void update_screen_particles (screen s, particle *ps, int n) {
    int i=0, j=0, x, y;
    for (i=0; i<n; i++) {
        x = ps [i].x;
        y = ps [i].y;
        s.ptr [y][x] = 'o';
    }
}

int update_screen_player (screen s, particle ply) {
    int stt = (s.ptr [ply.y][ply.x] != '\0')? 1: 0;
    s.ptr [ply.y][ply.x] = 'x';
    return stt;
}

void init_level () {
    stdgame.ply.y = stdgame.scr.ren/2;
    stdgame.ply.x = stdgame.scr.col/2;
    free (stdgame.pls);
    stdgame.pls = (particle*) malloc (level_settings [stdgame.level] * sizeof (particle));
    update_random (stdgame.pls, level_settings [stdgame.level], stdgame.scr.ren, stdgame.scr.col);
    int i=0;
    for (i=0; i<level_settings [stdgame.level]; ++i) {
        if (stdgame.pls [i].x == stdgame.ply.x && stdgame.pls [i].y == stdgame.ply.y)
        {
            update_particle_position_random (stdgame.pls+i, stdgame.scr.ren, stdgame.scr.col);
            continue;
        }
    }
    clear_screen (stdgame.scr);
    update_screen_player (stdgame.scr, stdgame.ply);
    update_screen_particles (stdgame.scr, stdgame.pls, level_settings [stdgame.level]);
}

void init_game (int ymax, int xmax) {
    create_screen (&(stdgame.scr), ymax, xmax);
    stdgame.level = 0;
    init_level ();
}

void next () {
    update_random (stdgame.pls, level_settings [stdgame.level], stdgame.scr.ren, stdgame.scr.col);
    update_screen_particles (stdgame.scr, stdgame.pls, level_settings [stdgame.level]);
}

void next_level () {
    stdgame.level += 1;
    init_level ();
}

bool collision_check () {
    bool stt = false;
    int i=0;
    for (i=0; i<level_settings [stdgame.level]; ++i) {
        if (stdgame.pls [i].x == stdgame.ply.x && stdgame.pls [i].y == stdgame.ply.y) {
            stt = true;
            stdgame.scr.ptr [stdgame.ply.y][stdgame.ply.x] = 'l';
            break;
        }
    }
    return stt;
}

void del_game () {
    free_screen (&(stdgame.scr));
    free (stdgame.pls);
}

#endif
