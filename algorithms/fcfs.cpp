#include "../include/scheduling.h"
#include<vector>
#include<algorithm>

bool compareArrivalTime(Process &proc1 , Process &proc2) {
    return proc1.arrival_Time < proc2.arrival_Time;
}

std::vector<Process> fcfs(std::vector<Process> &processes) {
    std::sort(processes.begin() , processes.end() , compareArrivalTime);

    int current_time = 0;
    for(int procIndex = 0 ; procIndex < processes.size() ; procIndex++) {
        if(current_time < processes[procIndex].arrival_Time) current_time = processes[procIndex].arrival_Time;
        processes[procIndex].completion_Time = current_time + processes[procIndex].burst_Time;
        processes[procIndex].turnaround_Time = processes[procIndex].completion_Time - processes[procIndex].arrival_Time;
        processes[procIndex].wait_Time = processes[procIndex].turnaround_Time - processes[procIndex].burst_Time;
        current_time = current_time + processes[procIndex].burst_Time;
    }
    
    return processes;
}