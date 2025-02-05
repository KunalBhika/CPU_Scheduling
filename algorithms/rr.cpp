#include "../include/scheduling.h"
#include<queue>
#include<algorithm>

bool CompareArrivalTime(Process &a , Process &b) {
    return a.arrival_Time < b.arrival_Time;
}

bool compareIds(Process &a, Process &b)
{
    return a.process_id < b.process_id;
}

std::vector<Process> rr(std::vector<Process> &processes , int tq) {
    std::vector<Process> result;
    std::deque<std::pair<Process , int>> dq;
    sort(processes.begin() , processes.end() , CompareArrivalTime);

    int current_time = processes[0].arrival_Time;
    int index = 0;
    int completedProcess = 0;

    while(completedProcess < processes.size()) {
        while(index < processes.size() && processes[index].arrival_Time <= current_time) {
            dq.push_back({ processes[index] , processes[index].burst_Time });
            index++;
        }

        if(dq.empty()) {
            current_time = processes[index].arrival_Time;
            continue;
        }

        std::pair<Process , int> frontProcess = dq.front();
        dq.pop_front();

        if(frontProcess.second <= tq) {
            completedProcess++;
            current_time += frontProcess.second;
            frontProcess.second = 0;
            frontProcess.first.completion_Time = current_time;
            frontProcess.first.turnaround_Time = frontProcess.first.completion_Time - frontProcess.first.arrival_Time;
            frontProcess.first.wait_Time = frontProcess.first.turnaround_Time - frontProcess.first.burst_Time;
            result.push_back(frontProcess.first);
        }
        else {
            frontProcess.second -= tq;
            current_time += tq;
            dq.push_back(frontProcess);
        }
    }

    std::sort(result.begin(), result.end(), compareIds);

    return result;
}