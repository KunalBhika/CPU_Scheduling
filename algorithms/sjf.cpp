#include "../include/scheduling.h"
#include <vector>
#include <queue>
#include <algorithm>

class CompareBurstTime
{
public:
    bool operator()(Process &proc1, Process &proc2)
    {
        return proc1.burst_Time > proc2.burst_Time;
    }
};

bool compareArrivalTime(Process &proc1, Process &proc2)
{
    return proc1.arrival_Time < proc2.arrival_Time;
}

std::vector<Process> sjf(std::vector<Process> &processes)
{
    std::vector<Process> result;
    std::priority_queue<Process, std::vector<Process>, CompareBurstTime> pq;
    std::sort(processes.begin(), processes.end(), compareArrivalTime);

    int current_time = 0;
    int procCount = 0;
    current_time = processes[0].arrival_Time;
    
    while (procCount < processes.size() && processes[procCount].arrival_Time <= current_time)
    {
        pq.push(processes[procCount]);
        procCount++;
    }

    while (!pq.empty())
    {
        Process shortestProc = pq.top();
        pq.pop();

        shortestProc.completion_Time = current_time + shortestProc.burst_Time;
        shortestProc.turnaround_Time = shortestProc.completion_Time - shortestProc.arrival_Time;
        shortestProc.wait_Time = shortestProc.turnaround_Time - shortestProc.burst_Time;

        current_time = current_time + shortestProc.burst_Time;

        for (int i = procCount; i < processes.size(); i++)
        {
            if (processes[i].arrival_Time <= current_time)
            {
                procCount++;
                pq.push(processes[i]);
            }
        }

        result.push_back(shortestProc);
    }

    return result;
}