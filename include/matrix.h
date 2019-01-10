#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIX {
    int col;
    int ren;
    char** ptr;
} matrix;

void fscanf_matrix (matrix m, FILE *fp);

void fprintf_matrix (matrix m, FILE *pf);

void create_matrix (matrix *m, int ren, int col);

void free_matrix (matrix *m);

#endif
