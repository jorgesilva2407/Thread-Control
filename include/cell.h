#ifndef CELL_H_
#define CELL_H_

#include <pthread.h>

#include "consts.h"

/* Uma posição específica do tabuleiro */
typedef struct {
    int count;               // Numero de threads na célula
    pthread_mutex_t cell_m;  // Mutex que controla o acesso ao contador
    pthread_cond_t cell_c;   // Sinalizadores de que uma thread de um groupo saiu da célula
    char group_u[MAX_N];     // Indicadores binarios se um grupo está ou não na célula
} Cell;

void init_cell(Cell* cell);

#endif
