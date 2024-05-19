#ifndef BOARD_H_
#define BOARD_H_

#include "cell.h"
#include "consts.h"

/* O tabuleiro por onde as threads se moverão */
typedef struct {
    int N;                   // Dimensão do tabuleiro
    Cell positions[20][20];  // Posições do tabuleiro
} Board;

void init_board(Board* board);

#endif
