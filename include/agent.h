#ifndef PATH_H_
#define PATH_H_

#include <stdlib.h>

#include "consts.h"
#include "position.h"

/* Informações relevantes de uma thread */
typedef struct {
    int id;                     // ID da thread
    int group;                  // Grupo da thread
    int positions;              // Número de posições que a thread percorrerá
    Positions path[2 * MAX_N];  // Posições e tempo que cada thread vai gastar
} Agent;

/* Lê os valores do caminho de uma variável */
void read_agent_positions(Agent *path);

#endif
