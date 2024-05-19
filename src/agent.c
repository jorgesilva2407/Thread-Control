#include <stdio.h>

#include "agent.h"

void read_agent_positions(Agent *agent) {
    for (int i = 0; i < agent->positions; i++) {
        scanf("%d %d %d", &agent->path[i].x, &agent->path[i].y, &agent->path[i].time);
    }
}
