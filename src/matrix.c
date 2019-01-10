#include "matrix.h"

void fscanf_matrix (matrix m, FILE *fp) {
    int i=0, j=0;
    for (i=0; i<m.ren; i++){
        for (j=0; j<m.col; j++){
            m.ptr [j][i] = getc (fp);
        }
    }
}

void fprintf_matrix (matrix m, FILE *pf) {
    int i=0, j=0;
    for (i=0; i<m.ren; i++){
        for (j=0; j<m.col; j++){
            fprintf (pf, "%c", m.ptr [j][i]);
        }
    }
}

void create_matrix (matrix *m, int ren, int col) {
    m->ren = ren, m->col = col;
    m->ptr = (char**) malloc (m->col * sizeof (char*));
    int i=0, j=0;
    for (i=0; i<m->col; i++){
        m->ptr [i] = (char*) malloc (m->ren * sizeof (char));
    }
}

void free_matrix (matrix *m) {
    int i=0;
    for (i=0; i<m->col; i++){
        free (m->ptr [i]);
    }
    free (m->ptr);
    m->ptr = NULL;
    m->ren = 0;
    m->col = 0;
}
