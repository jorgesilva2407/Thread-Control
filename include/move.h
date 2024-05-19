#ifndef MOVE_H_
#define MOVE_H_

#include <pthread.h>
#include <stdlib.h>

#include "agent.h"
#include "board.h"

/* Parâmetro que será passado na função move */
typedef struct {
    Agent* agent;
    Board* board;
} Agent_Board;

/* Realiza todos os moviementos de uma thread */
void* move(void* agent_board);

#endif
