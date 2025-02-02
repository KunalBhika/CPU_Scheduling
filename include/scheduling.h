#ifndef SCHEDULING_H
#define SCHEDULING_H

#include<vector>

class Process {
    public:
        int process_id;
        int arrival_Time;
        int burst_Time;
        int priority;            // for priority scheduling algorithms
        int completion_Time;
        int turnaround_Time;
        int wait_Time;
};

std::vector<Process> fcfs(std::vector<Process> &processes);
std::vector<Process> sjf(std::vector<Process> &processes);
std::vector<Process> srtf(std::vector<Process> &processes);
std::vector<Process> priorityScheduling(std::vector<Process> &processes);
std::vector<Process> rr(std::vector<Process> &processes);
std::vector<Process> mlq(std::vector<Process> &processes);

#endif