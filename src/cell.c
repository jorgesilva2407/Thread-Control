#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "cell.h"

void init_cell(Cell *cell) {
    cell->count = 0;
    pthread_mutex_init(&cell->cell_m, NULL);
    pthread_cond_init(&cell->cell_c, NULL);
    for (int i = 0; i < MAX_N; i++) {
        cell->group_u[i] = 0;
    }
}
