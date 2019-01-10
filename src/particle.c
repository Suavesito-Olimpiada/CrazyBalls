#include "particle.h"

void update_particle_position (particle *p, int y, int x) {
    p->x=x, p->y=y;
}

void update_particle_position_random (particle *p, int ymax, int xmax) {
    switch (rand ()%3) {
        case 0:
            break;
        case 1:
            p->x += 1;
            break;
        case 2:
            p->x += -1;
            break;
    }
    switch (rand ()%3) {
        case 0:
            break;
        case 1:
            p->y += 1;
            break;
        case 2:
            p->y += -1;
            break;
    }
    update_particle_position (p, (p->y+ymax)%ymax, (p->x+xmax)%xmax);
}

void update_random (particle *ps, int n, int ymax, int xmax) {
    int i=0;
    for (i=0; i<n; i++) {
        update_particle_position_random (ps+i, ymax, xmax);
    }
}
