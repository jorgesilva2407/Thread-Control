#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "agent.h"
#include "board.h"
#include "move.h"
#include "passa_tempo.h"
#include "tree.h"

int main() {
    int n_threads;
    Board board;
    scanf("%d %d", &board.N, &n_threads);

    pthread_t threads[n_threads];
    Agent agents[n_threads];
    Agent_Board pbs[n_threads];

    Tree hash;
    init_tree(&hash);

    for (int i = 0; i < n_threads; i++) {
        int id, group, positions;
        scanf("%d %d %d", &id, &group, &positions);

        agents[i].id = id;
        // Indices dos grupos sao convertidos para o intervalo [0, n_threads)
        agents[i].group = get_hash(&hash, group);
        agents[i].positions = positions;

        read_agent_positions(&agents[i]);

        pbs[i].agent = &agents[i];
        pbs[i].board = &board;
        pthread_create(&threads[i], NULL, move, &pbs[i]);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    exit(0);
}
