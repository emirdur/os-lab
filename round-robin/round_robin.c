#include <stdio.h>
#include "process.h"

// pid, burst_time, remaining_time
Process processes[] = {
    {1, 10, 10, 0},
    {2, 5, 5, 0},
    {3, 8, 8, 0}
};

int num_processes = sizeof(processes) / sizeof(processes[0]);

int time_quantum = 3;

void round_robin(Process processes[], int num_processes, int time_quantum) {
    int n = num_processes;
    int i = 0;
    int time = 0;

    while (num_processes > 0) {
        if (processes[i].remaining_time > 0) {
            int exec_time = (processes[i].remaining_time > time_quantum) ? time_quantum : processes[i].remaining_time;

            printf("Time %d: Process %d runs for %d units\n", time, processes[i].pid, exec_time);
            time += exec_time;

            processes[i].remaining_time -= exec_time;

            if (processes[i].remaining_time == 0) {
                processes[i].completion_time = time;
                num_processes -= 1;
            }
        }
        i = (i + 1) % n;
    }

    printf("Completion Times:\n");
    for (int j = 0; j < n; j++) {
        printf("Process %d completed at %d units\n", processes[j].pid, processes[j].completion_time);
    }
}

int main() {
    round_robin(processes, num_processes, time_quantum);
    return 0;
}