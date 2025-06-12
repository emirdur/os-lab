#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
} Process;

#endif