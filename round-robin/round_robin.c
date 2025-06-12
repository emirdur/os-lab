#include <stdio.h>
#include "process.h"

// pid, burst_time, remaining_time
Process processes[] = {
    {1, 10, 10},
    {2, 5, 5},
    {3, 8, 8}
};

int num_processes = sizeof(processes) / sizeof(processes[0]);

int time_quantum = 3;

void round_robin(Process processes[], int num_processes, int time_quantum) {
    int n = num_processes;
    int i = 0;
    while (num_processes > 0) {

        if (processes[i].remaining_time > 0) {
            if (processes[i].remaining_time > time_quantum) {
                processes[i].remaining_time -= time_quantum;
            } else {
                processes[i].remaining_time = 0;
                num_processes -= 1;
            }
        }

        i = (i + 1) % n;
    }
}

int main() {
    round_robin(processes, num_processes, time_quantum);
}