#include "../include/scheduling.h"
#include <algorithm>
#include <queue>

bool CompareArrivalTime(Process &a, Process &b)
{
    return a.arrival_Time < b.arrival_Time;
}

class CompareProcesses
{
public:
    bool operator()(Process &proc1, Process &proc2)
    {
        return proc1.priority > proc2.priority;
    }
};

std::vector<Process> priorityScheduling_NP(std::vector<Process> &processes)
{
    std::vector<Process> result;
    std::priority_queue<Process, std::vector<Process>, CompareProcesses> pq;
    sort(processes.begin(), processes.end(), CompareArrivalTime);

    int current_time = processes[0].arrival_Time;
    int index = 0;
    int completedProcess = 0;

    while (completedProcess < processes.size())
    {
        while (index < processes.size() && processes[index].arrival_Time <= current_time)
        {
            pq.push(processes[index]);
            index++;
        }

        if (pq.empty())
        {
            current_time = processes[index].arrival_Time;
            continue;
        }

        Process priorityProcess = pq.top();
        pq.pop();
        current_time += priorityProcess.burst_Time;
        completedProcess++;

        // mark Completed
        priorityProcess.completion_Time = current_time;
        priorityProcess.turnaround_Time = priorityProcess.completion_Time - priorityProcess.arrival_Time;
        priorityProcess.wait_Time = priorityProcess.turnaround_Time - priorityProcess.burst_Time;

        result.push_back(priorityProcess);
    }

    std::sort(result.begin(), result.end(), CompareArrivalTime);

    return result;
}