#ifndef POSITIONS_H_
#define POSITIONS_H_

/* Uma posição e o tempo que uma thread precisa ficar nela */
typedef struct {
    int x;     // Posição no eixo x
    int y;     // Posição no eixo y
    int time;  // Tempo que precisa ficar na posição
} Positions;

#endif
