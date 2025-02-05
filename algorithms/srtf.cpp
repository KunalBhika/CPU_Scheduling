#include "../include/scheduling.h"
#include <queue>
#include <algorithm>

class CompareBurstTime
{
public:
    bool operator()(std::pair<Process, int> &a, std::pair<Process, int> &b)
    {
        if (a.second != b.second)
            return a.second > b.second; // if remaining time is same execute process which arrived first
        return a.first.arrival_Time > b.first.arrival_Time;
    }
};

bool compareArrivalTime(Process &a, Process &b)
{
    return a.arrival_Time < b.arrival_Time;
}

bool compareIds(Process &a, Process &b)
{
    return a.process_id < b.process_id;
}

std::vector<Process> srtf(std::vector<Process> &processes)
{
    std::priority_queue<std::pair<Process, int>, std::vector<std::pair<Process, int>>, CompareBurstTime> pq;
    sort(processes.begin(), processes.end(), compareArrivalTime);

    std::vector<Process> result;

    int current_time = processes[0].arrival_Time;
    int completedProcesses = 0;
    int index = 0;

    while (completedProcesses < processes.size())
    {
        while (index < processes.size() && processes[index].arrival_Time == current_time)
        {
            pq.push({processes[index], processes[index].burst_Time});
            index++;
        }

        if(pq.empty()) {
            current_time = processes[index].arrival_Time;
            continue;
        }

        std::pair<Process, int> smallestProc = pq.top();
        pq.pop();
        smallestProc.second--;
        current_time++;

        if (smallestProc.second != 0)
            pq.push(smallestProc);
        else
        {
            // mark completed
            completedProcesses++;
            smallestProc.first.completion_Time = current_time;
            smallestProc.first.turnaround_Time = smallestProc.first.completion_Time - smallestProc.first.arrival_Time;
            smallestProc.first.wait_Time = smallestProc.first.turnaround_Time - smallestProc.first.burst_Time;
            result.push_back(smallestProc.first);
        }
    }

    std::sort(result.begin(), result.end(), compareIds);

    return result;
}