#include "board.h"

void init_board(Board *board) {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            init_cell(&board->positions[i][j]);
        }
    }
}
