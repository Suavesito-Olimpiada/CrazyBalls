#ifndef _PARTICLE_H
#define _PARTICLE_H

typedef struct PARTICLE {
    int x, y;
} particle;

void update_particle_position (particle *p, int y, int x);

void update_particle_position_random (particle *p, int ymax, int xmax);

void update_random (particle *ps, int n, int ymax, int xmax);

#endif
