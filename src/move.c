#include <pthread.h>
#include <stdio.h>

#include "consts.h"
#include "move.h"
#include "passa_tempo.h"

void* move(void* agent_board) {
    Agent* agent = ((Agent_Board*)agent_board)->agent;
    Board* board = ((Agent_Board*)agent_board)->board;

    for (int i = 0; i < agent->positions; i++) {
        int x = agent->path[i].x;
        int y = agent->path[i].y;
        int time = agent->path[i].time;

        Cell* c = &board->positions[x][y];

        // Thread trava o recurso compartilhado para verificar se pode entrar
        pthread_mutex_lock(&c->cell_m);

        /* Se a thread não puder entrar então ela esperar alguma outra
         * thread sair e verifica se isso permite que ela entre agora */
        while (c->count >= MAX_THREADS || c->group_u[agent->group] == 1) {
            pthread_cond_wait(&c->cell_c, &c->cell_m);
        }

        // Incrementa o número de thread na célula
        c->count++;

        // Indica que uma célula de um determinado grupo está na célula
        c->group_u[agent->group]++;

        // Libera os recursos da célula
        pthread_mutex_unlock(&c->cell_m);

        passa_tempo(agent->id, x, y, time);

        // Thread sai da célula
        pthread_mutex_lock(&c->cell_m);
        c->group_u[agent->group]--;
        c->count--;
        pthread_cond_signal(&c->cell_c);
        pthread_mutex_unlock(&c->cell_m);
    }

    return NULL;
}
