#include <stdio.h>
#include "process.h"

// pid, burst_time, remaining_time
Process processes[] = {
    {1, 10, 10},
    {2, 5, 6},
    {3, 8, 8}
};

int num_processes = sizeof(processes) / sizeof(processes[0]);